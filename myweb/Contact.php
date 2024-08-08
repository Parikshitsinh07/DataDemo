<style>
.user-panel {
      position: absolute;
        right: 127px;
        top: 73px;                    
    }

    .user-dropdown {
        position: relative;
        display: inline-block;
    }

    .user-icon {
        width: 30px;
        height: 30px;
        border-radius: 50%;
        margin-right: 10px;
    }

    .dropdown-btn {
        background-color: transparent;
        border: none;
        outline: none;
        cursor: pointer;
        font-size: 16px;
    }

    .dropdown-content {
        display: none;
        position: absolute;
        right: 0;
        z-index: 1;
    }

    .dropdown-content a {
        display: block;
        padding: 10px 20px;
        text-decoration: none;
        color: #333;
    }

    .dropdown-content a:hover {
        background-color: #ddd;
    }

    .user-dropdown:hover .dropdown-content {
        display: block;
    }
</style>

<?php include('header.html')?>
    <!--------------------- Contect Us ---------------->
    <div class="contact-page">
        <div class="container">
            <div class="row">
                <div class="col-2">
                    <img src="images/contact.jpg" class = "malav" alt="Contact-Pic" width="60%"  />
                </div>
                <div class="col-2">
                    <form id="contactForm" onsubmit="return validateForm()" action="contact.php" method="post">
                        <h2>Contact Us</h2>
                        <input type="text" placeholder="Your Name" id="name" name= "uname"/>
                        <span class="error" id="nameError"></span>
                        <input type="email" placeholder="Your Email" id="email"  name="email"/>
                        <span class="error" id="emailError"></span>
                        <input type="text" placeholder="Subject" id="subject"name="usubject" />
                        <span class="error" id="subjectError"></span>
                        <textarea placeholder="Message" id="message" name="umessage"></textarea>
                        <span class="error" id="messageError"></span>
                        <button type="submit" name="submit" class="btn">Send Message</button>
                    </form>
                </div>
            </div>
        </div>
    </div>
    <?php
    session_start();
    if(isset($_SESSION['userid'])){
        $user=$_SESSION['userid'];
    echo '<div class="user-panel">
        <div class="user-dropdown">
            <img class="user-icon" src="images/usericon.png"> 
            <div class="dropdown-content">
            <a href="#"><button class="dropdown-btn">'.$user.'</button></a>';
            if($user=="Malav" || $user=="Pappu"){
              echo ' <a href="admin.php">Admin</a> ';
            }
           echo '
                <a href="#">User History</a>
                <a href="logout.php">Logout</a>
            </div>
        </div>
    </div>';}
    if(isset($_POST["submit"])){
        
        $host = 'localhost';
        $username = 'root';
        $password = '';
        $database = 'bookstore';
      
        $con = mysqli_connect($host,$username,$password,$database);
        if(!$con){
            echo "Cant connect to database";
            mysqli_error();
        }
    
          $username = $_POST['uname'];
          $useremail = $_POST['email'];
          $usersubject = $_POST['usubject'];
          $usermessage = $_POST['umessage'];
     

              
     $query = "INSERT INTO user_contact(user_name,User_email, user_subject,user_message) VALUES ('".$username."','".$useremail."','".$usersubject."','".$usermessage."')" ;
           
              $result = mysqli_query($con, $query);     
              if($result=true){
                echo "
                <script> 
              alert('Thank You for Contact Us ');
            </script>";
              }
          
          

              mysqli_close($con);
     }
   ?> 
    <?php include('footer.html')?>
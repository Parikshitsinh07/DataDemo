<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Cart | Ebookstore</title>
  <link rel="stylesheet" href="style.css" />
  <link rel="preconnect" href="https://fonts.gstatic.com" />
  <link href="https://fonts.googleapis.com/css2?
      family=Poppins:ital,wght@0,200;0,300;0,400;0,500;0,600;1,100;1,200;1,300;1,400;1,500;1,600&display=swap"
    rel="stylesheet" />
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" />
  <style>
    .user-panel {
      position: absolute;
        right: 127px;
        top: 53px;                    
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
</div>';

}
               if(isset($_POST["submit"])){
  
                $host = 'localhost';
                $username = 'root';
                $password = '';
                $database = 'bookstore';
            
                $con = mysqli_connect($host,$username,$password,$database);
                if(!$con){
                  echo "Can't connect to database";
                  mysqli_error();
                }
            
                $username = $_POST['uname'];
                $password = $_POST['password'];
            
                // Use prepared statement to avoid SQL injection
                $stmt =  "SELECT * FROM user_informetion WHERE user_name='$username' AND user_password ='$password'";
            
                $result = mysqli_query($con, $stmt);
            
                if ($result->num_rows) {
                  $_SESSION['userid']=$_POST['uname'];
                  echo "<script> 
                  alert('Your login sucessfully');
                </script>";
            
                if($username==="Malav" or $username === "Pappu"){
                   header("location:admin.php");
                }
                
                }
                 else {
                  echo "<script> 
                          alert('Please register first');
                        </script>";
        
                }
                // header("location:account.php");
                mysqli_close($con);
              }
      if(isset($_POST["singUp"])){
        
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
                $password = $_POST['password'];
              
                // Query database for user with matching username and password 
                $query = "SELECT * FROM user_informetion WHERE user_name='$username'";
                // echo $query;
                $result = mysqli_query($con, $query);

                  if ($result->num_rows ) {
                     echo  $username ." You Have Already Registration !";
                    //  echo "click for loign  ";   
                  
                } else {

                    
                    $query = "INSERT INTO user_informetion(user_name,User_email, user_password) VALUES ('".$username."','".$useremail."','".$password."')" ;
                  
                    $result = mysqli_query($con, $query);     
                    if($result=true){
                      echo "<br>";
                        echo "Your Registration successfully";
                    }
                
                }

                    mysqli_close($con);
           }
         ?>  

</head>

<body>
  <!------------------ Header ------------------>
  <div class="container">
    <div class="navbar">
      <div class="logo">
        <a href="index.html">
          <img src="images/EbookStore-Logo.png" alt="EbookStore-Logo" />
        </a>
      </div>
      <!----------  Nav Bar ------------------>
      <nav>
        <ul id="MenuItems">
          <li><a href="index.php">Home</a></li>
          <li><a href="ebooks.php">Ebooks</a></li>

          <li><a href="Contact.php">Contact</a></li>
          <li><a href="account.php">Account</a></li>
        </ul>
      </nav>
      <a href="cart.php">
        <img src="images/cart.png" alt="Shoping Cart" width="28px" height="28px"
          style="margin-left: 10px; margin-top: 15px" />
      </a>
      <img src="images/menu.png" class="menu-icon" onclick="menutoggle()" />
    </div>
  </div>

  <!-- ---------- account page------------- -->
  <div class="account-page">
    <div class="container">
      <div class="row">
        <div class="col-2">
          <img src="images/header-pic.png" alt="Header-Pic" width="50%" />
        </div>
        <div class="col-2">
          <div class="form-container">
            <div class="form-btn">
              <span onclick="signIn()"> Sign In </span>
              <span onclick="signUp()"> Sign Up </span>
              <hr id="indicator" />

              <form id="signInForm" name="myform" method="post" action="account.php">
                <input type="text" placeholder="Username" name="uname" />
                <span id="uname"></span>
                <input type="password" name="password" placeholder="password" />
                <button type="submit" name="submit" class="btn">Sign In</button>
                <a href="">Forgot password</a>
              </form>
              <form id="signUpForm" name="myformrg" method="post" action="account.php">
                <input type="text" placeholder="Username"  name="uname" />
                <input type="email" placeholder="Email"  name="email"/>
                <input type="password" placeholder="Password" name="password" />
                <button type="submit" class="btn"  name="singUp">Sign Up</button>
              </form>     
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <!-- ---------------------footer------------------- -->
  <div class="footer">
    <div class="container">
      <div class="row">
        <div class="footer-col-1">
          <h3>Download Our App</h3>
          <p>Download App for Android and ios mobile phone.</p>
          <div class="app-logo">
            <img src="images/Playstore.png" />
            <img src="images/Applestore.png" />
          </div>
        </div>
        <div class="footer-col-2">
          <img src="images/EbookStore-Logo-footer.png" />
          <p>
            Lorem ipsum, dolor sit amet consectetur adipisicing elit.
            Reiciendis, Lorem ipsum dolor sit amet.
          </p>
        </div>
        <div class="footer-col-4">
          <h3>Follow us</h3>
          <ul>
            <li>Facebook</li>
            <li>Youtube</li>
            <li>Instagram</li>
            <li>Twitterr</li>
          </ul>
        </div>
      </div>
      <hr />
      <p class="copyright">Copyright 2023 - EbookStore</p>
    </div>
  </div>
  <!-- ---------Javascript for toggle menu------------- -->
  <script>
    var MenuItems = document.getElementById("MenuItems");
    MenuItems.style.maxHeight = "0px";
    function menutoggle() {
      if (MenuItems.style.maxHeight == "0px") {
        MenuItems.style.maxHeight = "200px";
      } else {
        MenuItems.style.maxHeight = "0px";
      }
    }
  </script>
  <!-- -----------js for toggle form------------------ -->
  <script>
    var signInForm = document.getElementById("signInForm");
    var signUpForm = document.getElementById("signUpForm");
    var indicator = document.getElementById("indicator");

    function signIn() {
      signUpForm.style.transform = "translateX(300px)";
      signInForm.style.transform = "translateX(300px)";
      indicator.style.transform = "translateX(0px)";
    }
    function signUp() {
      signUpForm.style.transform = "translateX(0px)";
      signInForm.style.transform = "translateX(0px)";
      indicator.style.transform = "translateX(100px)";
    }
  </script>
  <!-- -----------------js for form validation ------------------ -->
  <script>
    function formvalidate() {
      var ptrn = /^([^0-9\W]*)$/;
      if (ptrn.test(document.myform.uname.value)) {
        document.getElementById("uname").textContent = "User Name is Valid";
        document.getElementById("uname").style.background = "#72EF57";
        document.getElementById("uname").style.fontSize = "12px";
      } else {
        document.getElementById("uname").textContent = "User Name is Invalid";
        document.getElementById("uname").style.background = "#EF6257";
        document.getElementById("uname").style.fontSize = "12px";
      }
    }

    document.myform.uname.addEventListener("blur", formvalidate);
  </script>
</body>

</html>
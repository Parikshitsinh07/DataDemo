<style>
   .row{
    margin:0px 150px;
    text-align:center;
   }
   #but{
     margin:8px 0px 30px 200px;
   }
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
    #youtub{
      width:560px ;
      height:315px;
    }
</style>

<?php

?>
<?php include('header.html')?>
<div class="small-container">
    <div class="row row-2">
      <h2>Adventure</h2>
      
    </div>
</div>
<?php
  //  if(isset($_POST["submit"])){
    // Establish database connection
    session_start();
if(isset($_SESSION['userid'])){
  $user=$_SESSION['userid'];
echo '<div class="user-panel">
    <div class="user-dropdown">
        <img class="user-icon" src="images/usericon.png"> 
        <div class="dropdown-content">
        <a href="#"><button class="dropdown-btn">'.$user.'</button></a>';
        if($user=="Malav" || $user=="Pappu"){
          echo ' <a href="admin.php">Admin </a> ';
        }
       echo '
            <a href="#">User History</a>
            <a href="logout.php">Logout</a>
        </div>
    </div>
</div>';

}
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "bookstore";
    
    $con =  mysqli_connect($servername, $username, $password, $dbname);
    
    // Check connection
    if(!$con){
        echo "Cant connect to database";
        mysqli_error();
       }
    
    $sql =  "SELECT * FROM book_information WHERE book_categari = 'Adventur'";
    
  
  
       // Execute query
       $result = mysqli_query($con, $sql);
      //  $row = mysqli_fetch_assoc($result);
       // Display results
       if (mysqli_num_rows($result) > 0) {
       
          echo " <div class='row'>";
          
        while($row = mysqli_fetch_assoc($result)){
                   echo"<div class='col-4'>
                     <a href='".$row['book_page']."'>
                   <img src='".$row['book_img']."' alt='Book 4' />
                     </a>
                <a href='book-detail.php'>
                <h4 id=''>".$row['book_name']."</h4>
                 </a>
               <div class='rating'>
                   <i class='fa fa-star'></i>
                   <i class='fa fa-star'></i>
                   <i class='fa fa-star'></i>
                   <i class='fa fa-star'></i>
                   <i class='fa fa-star-o'></i>
                  </div>
                <p>".$row['book_price']."</p>
            </div>";
               }
              echo "</div>";
            
          }
             else {
           echo "No Recode found.";
             }

       // Close connection
       mysqli_close($con);

  //  }

?>
  <!-- ---------------------Youtube Video------------------- -->
  <div class="youtube-container">
      <div class="youtube-row">
        <div class="col-2">
          <h2>5 Books You Must Read If You're Serious About Success</h2>
        </div>
        <div class="col-2">
         <?php
         echo ' <iframe id="youtub" width="560px" height="315" src="https://www.youtube.com/embed/LqJBXtG9xxk"
            frameborder="0"
            allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
            allowfullscreen></iframe>';
            ?>
        </div>
      </div>
    </div>

    <!-- -->
    <div class="page-btn" id="but">
      <span>1</span>
      <span>2</span>
      <span>3</span>
      <span>4</span>
      <span>&#8594;</span>
    </div>
  </div>
<?php include('footer.html')?>




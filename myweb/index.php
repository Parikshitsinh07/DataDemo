<style>
  
  </style>
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
        .box-container-wrapper {
    max-width: 1200px;
    margin: 35px auto;
  }
  
  .box-container {
    display: flex;
    justify-content: space-between;
  }
  
  .box {
    height: 200px;
    width: 350px;
    border: 1px solid black;
    display: flex;
    justify-content: center;
    align-items: center;
    position: relative;
    overflow: hidden;
    transition: all 0.5s ease;
  }
  
  .story-book {
    background-color: lightblue;
  }
  
  .novel {
    background-color: lightgreen;
  }
  
  .adventure {
    background-color: yellow;
  }
  
  .box:hover {
    transform: scale(1.1);
  }
  
  .box a {
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    text-align: center;
    position: absolute;
    top: 79px;
    left: 60px;
  }
  #row{
    margin:0px 150px;
    text-align:center;
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
             if($user=="Malav"){
               echo ' <a href="admin.php">Admin</a> ';
             }
            echo '
                <a href="#">User History</a>
                <a href="logout.php">Logout</a>
            </div>
        </div>
    </div>';
  }
   include('header.html')?>
<div class="row">
        <div class="col-2">
          <h1>
            The Books Lover<br />
            Read all About it!
          </h1>
          <p>
          At our bookstore, we don't just sell books - we offer a journey through time, space, and the human experience.

          </p>
          <a href="ebooks.php" class="btn">Explore Now &#x27F6;</a>
        </div>
        <div class="col-2">
          <img src="images/header-pic.png" alt="Header Pic" />
        </div>
      </div>
       <!---------------- categories -------------------->
       <div class="box-container-wrapper">
    <div class="box-container">
      <div class="box story-book">
        <a href="storybook.php">
          <h2 class="cat">Story Book</h2>
          <p>In the end, we'll all become stories.
</p>
        </a>
      </div>
      <div class="box novel">
        <a href="novel.php">
          <h2 class="cat">Novel</h2>
          <p>“A room without books is like a body without a soul.”</p>
        </a>
      </div>
      <div class="box adventure">
        <a href="advanture.php">
          <h2 class="cat">Adventure</h2>
          <p>"Discover your next great adventure between the pages of our books"</p>
        </a>
      </div>
    </div>
  </div>

  <?php 
   
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
       $sql =  "SELECT * FROM book_information ";
  
       // Execute query
       $result = mysqli_query($con, $sql);
       if (mysqli_num_rows($result) > 0) {
      echo'  <h2 class="title">Featured Titles</h2>';
        echo " <div class='row' id='row'>";
        
      while($row = mysqli_fetch_assoc($result)){
          
            if($row['book_id']<5){
           
         
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
             }
            echo "</div>";
        }
           else {
         echo "No Recode found.";
           }
          echo'<h2 class="title">Bestsellers</h2>'; 
          $sql2 =  "SELECT * FROM book_information book_id";
  
          // Execute query
          $result2 = mysqli_query($con, $sql2);
   
          if (mysqli_num_rows($result) > 0) {
        
              echo " <div class='row' id='row'>";
              
            while($row = mysqli_fetch_assoc($result2)){
                
                  if($row['book_id']>=6){
                 
               
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
                   }
                  echo "</div>";
              }
                 else {
               echo "No Recode found.";
                 }

     // Close connection
     mysqli_close($con);

?>
<!------------------offer ------------>
<div class="offer">
    <div class="small-container">
      <div class="row">
        <div class="col-2">
          <img src="images/offer-Book.jpg" class="offer-img" />
        </div>
        <div class="col-2">
          <p>Available on EbookStore</p>
          <br />
          <h2>I Do nott Want To Die Poor</h2>
          <br />
          <small>
            Making Michael Arceneauxs I Do not Want to Die Poor required
            reading in high schools across the country would help a lot of
            young people think twice about the promise that going to college
            at any cost is the only path to upward social mobility.
          </small>
          <a href="offerBook.php" class="btn">Buy Now &#8594;</a>
        </div>
      </div>
    </div>
  </div>';

<?php include('footer.html')?>
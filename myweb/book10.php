
<style>
   #row{
    margin:0px 150px;
    text-align:center;
   }
   #but{
     margin:8px 0px 30px 200px;
   }

#btn2 {
    width: 55%;
    border: none;
    cursor: pointer;
    margin: 10px 0;
    background:#36d013;
}
#dd{
  width: 500px;
}
#add{
  margin:10px 10px;
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
</style>
<?php include('header.html')?>
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

  //  if(isset($_POST["submit"])){
    // Establish database connection
    
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "bookstore";
    
    $con =  mysqli_connect($servername, $username, $password, $dbname);
   
      $_SESSION['cart'] = 10;
    
    // Check connection
    if(!$con){
        echo "Cant connect to database";
        mysqli_error();
       }
    
       $sql1 =  "SELECT * FROM `book_information` WHERE book_id=10";
       $result1 = mysqli_query($con, $sql1);
       if (mysqli_num_rows($result1) > 0) {
        
      while($book = mysqli_fetch_assoc($result1)){
  echo '<!-- ----------single product details------------- -->
  <div class="small-container single-product">
    <div class="row">
      <div class="col-2">
        <img src="'.$book['book_img'].'" alt="Book4" width="68%" />
      </div>
      <div class="col-2">
        <p>Home / Ebook</p>
        <h1>'.$book['book_name'].'</h1>
        <h4>Rs.'.$book['book_price'].'</h4>
        <form id="add" action="cart.php" method="post">
        <input type="number" value="1" name="items"/>
        <!-- <input type="hidden" name="book1" value="56"> -->
        <a href=""><input id="btn2" type="submit"  name="submit" value="Add To Cart"></a>
  </form>
        <h3>Book Deatails <i class="fa fa-indent"></i></h3>
        <br />
        <p id="dd">
          Acclaimed by many as the worlds greatest novel, Anna Karenina
          provides a vast panorama of contemporary life in Russia and of
          humanity in general. In it Tolstoy uses his intense imaginative
          insight to create some of the most memorable characters in all of
          literature. Anna is a sophisticated woman who abandons her empty
          existence as the wife of Karenin and turns to Count Vronsky to
          fulfil her passionate nature - with tragic consequences. Levin is a
          reflection of Tolstoy himself, often expressing the authors own
          views and convictions.
        </p>
      </div>
    </div>
  </div>

  <!-- -------------title----------------- -->
  <div class="small-container">
    <div class="row row-2">
      <h2>Related Books</h2>
      <p>View More</p>
    </div>
  </div>';
      }
    }
    
  $sql =  "SELECT * FROM book_information ";
  
       // Execute query
       $result = mysqli_query($con, $sql);
      // $row = mysqli_fetch_assoc($result);
       // Display results
       //  $num=mysqli_num_rows($result);
       if (mysqli_num_rows($result) > 0) {
        
          echo " <div class='row' id='row'>";
          
        while($row = mysqli_fetch_assoc($result)){
            
              if($row['book_id']<5){
             
           
                   echo"<div class='col-4'>
                     <a href='book-detail.php'>
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

  //  }

?>

  
  <?php include('footer.html')?>
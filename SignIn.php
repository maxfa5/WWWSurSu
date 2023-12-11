    <section id="SignIn">
        <div id="textForSignIn">
            <h1 id="glavSignIn">Sign Up Our Newsletter</h1>
            <p id="SignInp">The state of Utah in the United States is home to lots of beautiful National Parks, & Bryce Canyon National Park ranks as three of the most magnificent.</p>
        </div>
        <div id="formsForSignIn">
                        <?php
        $number_phone = $_POST['phoneNum'];
        $mail = $_POST["mail"];
        $password = $_POST["password"];
        if(isset($mail) ){        echo    "<h1 class='hello_block' style='    text-align:center; background-color:white; color:black;'>HEllO  $mail</h1>";}
        ?>
            <form id="form" method="post" action="index.php">
                <input class="inputdann" name ="password" type="password" placeholder="Password">
                <input class="inputdann" name="phoneNum" type="tel" placeholder="Number phone">
                <input class="inputdann" name = "mail" type="email" placeholder="Email">
                <input type="submit" id="SignInButton" placeholder="Sign in">
            </form>
        </div>
    </section>

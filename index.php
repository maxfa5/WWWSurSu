<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/style.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=AR+One+Sans&display=swap" rel="stylesheet">
    <title>Document</title>
</head>

<body>
        <?php
        $head = file_get_contents('header.html');
        $travelPro = file_get_contents('travelPro.html');
        $Article = file_get_contents('Article.html');
        $footer = file_get_contents('footer.html');
        echo $head;
        echo $travelPro;
        echo $Article;
        include 'SignIn.php';
        echo $footer;
        ?>

    <script src="script.js"></script>
</body>

</html>

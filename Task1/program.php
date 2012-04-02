#!/usr/bin/php -q
<?php
    echo "Task1 (PHP Script) - Irnes Mujkanovic" .PHP_EOL;

    // File containing test data
    $filename = $argv[1];
    $fhandle = @fopen($filename, "r");

    $delimiter_row = "+---+---+---+---+";

    if($fhandle)
    {
        echo "Content of file: $filename" .PHP_EOL;
        // Read each line and print it to the screen
        $row_number = 0;
        while(($buff = fgets($fhandle)) !== false)
        {
            if($row_number == 0)
                echo $delimiter_row . PHP_EOL;

            //clear previous content
            $delimiter_row = "";

            $linelength = strlen($buff);
            for($i = 0; $i < $linelength; $i++)
            {
                // print every second character from row
                if(($i % 2) == 0)
                {
                    echo "| " .$buff[$i] ." ";
                    // compose row delimiter based on row content
                    $delimiter_row .= "+";
                    if($buff[$i] == ' ')
                        $delimiter_row .= "   ";
                    else
                        $delimiter_row .= "---";
                }

                // complete row delimiter
                if($i == $linelength - 1)
                {
                    echo "|" .PHP_EOL;
                    $delimiter_row .= "+";
                }
            }
            $row_number++;

            echo $delimiter_row .PHP_EOL;
         }

        // Close the file when we're finished
        fclose($fhandle);
    }
    else
    {
        echo "Unable to open file: $filename" .PHP_EOL;
    }
?>
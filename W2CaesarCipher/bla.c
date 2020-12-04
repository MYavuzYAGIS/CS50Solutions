int key; 
    // Argument Filtering. Now It accepts only positive integers
    if(argc<2)
    {
      printf("Too few positional arguments\n");
      printf("Usage: ./caesar key \n");
      free(plain);
      return EXIT_FAILURE;
      
    }
    else if( argc > 2 ) 
    {
      printf("Too many positional arguments\n");
      printf("Usage: ./caesar key \n");
      free(plain);
      return EXIT_FAILURE;
      
    }
    else if (argc ==2)
    {
        if (!isdigit(atoi(argv[1])))
        {
            key = atoi(argv[1]);
            // Controlling whether the key is greater than or equal to 26. It will return the remainder as real key value
            // the best condition, the value is between 1 and 26
            if(key>0 && key <=26){
                printf("key is Secured!\n");
                key = atoi(argv[1]);

            }
            // assigned key is greater than 26, thus, rotating it and reassigining to key value so there is no overflow in the ascii table.
            else if(key > 26)
            {
                key = key %26;
                key = atoi(argv[1]);
            }
            else{
                printf("Key cannot be a negative integer or 0. Given parameter is %d\n",key);
                free(plain);
                return EXIT_FAILURE;
            }
            
        }else{
            printf("Given argument is not a positive integer\n");
            EXIT_FAILURE;
        }
    }
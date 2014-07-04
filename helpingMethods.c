



/***                                                                                                                                                                                          
 * get_db_config                                                                                                                                                                                                                           
 * Method that gets the database information of the config_file and asings the info on global variables                                                                                                                                     * @params - none                                                                                                                                                                                                  
 * @return - int, -1 if error && 0 if success                                                                                                                                                                                              
 ***********************************************************/
int get_db_config(){

  //Local variables                                                                                                                                                                                                                         
  FILE * config_file = fopen( ".config_file", "r+" );
  char line[100];
  int ban = -1;

  //Validation fot the existence of the file                                                                                                                                                                                                
  if( config_file == NULL){
    printf( "Error opening .config_file file.\n" );
    return( -1 );
  }//End of the error validation                                                                                                                                                                                                           

  //loop for reading line by line                                                                                                                                                                                                           
  while( fgets( line, 100, config_file ) != NULL ){

    //Validation of the cometarized lines                                                                                                                                                                                                   
    if( line[0] != ';' ){

      //The database line part toggle validation                                                                                                                                                                                            
      if( strstr( line, "database" ) != NULL ){

        ban *= -1;
        fgets( line, 100, config_file );

      }//End of the line on the database part toggle                                                                                                                                                                                        

      //Validation fot the toggle of the correct line that is in the database part                                                                                                                                                          
      if( ban == 1 ){

        //Other local variables                                                                                                                                                                                                             
        int i = 0;
        int ban2 = -1;

        //Loop for reading char by char the line                                                                                                                                                                                            
        for( i = 0; i < strlen( line ); i++ ){
          //Validation for the right word and changin the toggle                                                                                                                                                                            
          if( line[i] == '\'' ){
            ban2 *= -1;
            i++;
          }//Enf of validation of right word                                                                                                                                                                                                

          //Validation of the toggle                                                                                                                                                                                                        
          if( ban2 == 1 ){

            if( strstr( line, "url" ) != NULL ){
              append( url, line[i] );
            } else if( strstr( line, "username" ) != NULL ){
              append( username, line[i] );
            } else if( strstr( line, "password" ) != NULL ){
              append( password, line[i] );
            } else if( strstr( line, "db_name" )  != NULL ){
              append( db_name, line[i] );
            }

          }//End of toggle validation                                                                                                                                                                                                       

        }//End of the loop for the char by char                                                                                                                                                                                             

      }//End of validation of the toggle of the line                                                                                                                                                                                        

    }//End of validation of the not comentarized line

  }//End of the line by line loop                                                                                                                                                                                                           

  fclose( config_file );

  return( 0 );

}//End of reading_file_line_by_line Method                                                                                                                                                                                                  

/***
 * append
 * Method that concatenates a char to a string bitch!
 * @param char * s -  string 
 * @param char c - character
 * @return none
 *********************************/
void append(char* s, char c)
{

  int len = strlen(s);
  s[len] = c;
  s[len+1] = '\0';

}//End of append Method

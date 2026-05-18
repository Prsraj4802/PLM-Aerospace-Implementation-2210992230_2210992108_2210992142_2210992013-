// 4) Batch Utility – Item create using TCTYPE_create_object (in home folder) 

// --- Header Files ---
#include<conio.h> 
#include<stdio.h> 
#include<tcinit/tcinit.h> 
#include<tc/emh.h> 
#include<tc/tc_startup.h> 
#include<tccore/item.h> 
#include<sa/user.h> 
#include<tc/folder.h> 
#include<tccore/aom.h> 
#include<tccore/tctype.h> 
#include<ae/dataset.h> 
#include<ae/datasettype.h> 
#include<tccore/grm.h> 
#include<tccore/aom_prop.h>

// --- Program ---
#include"Header.h" 
 
int Item_create1(char* id, char* name, char* u) 
{ 
 int ifail3; 
 char* error3; 
 tag_t item_type,create_IP,BO,user,home; 
 
 ifail3 = TCTYPE_find_type("Item", "Item", &item_type); 
 ifail3 = TCTYPE_construct_create_input(item_type, &create_IP); 
 ifail3 = AOM_set_value_string(create_IP, "item_id", id); 
 ifail3 = AOM_set_value_string(create_IP, "object_name", name); 
 ifail3 = TCTYPE_create_object(create_IP, &BO); 
 if (ifail3 == ITK_ok) 
 { 
  printf("\n\t***Item created successfully***"); 
 } 
 else 
 { 
  EMH_ask_error_text(ifail3, &error3); 
  printf("\n\t%s", error3); 
 } 
 
 ifail3 = AOM_save(BO); 
 ifail3 = SA_find_user2(u, &user); 
 ifail3 = SA_ask_user_home_folder(user, &home); 
 ifail3 = FL_insert(home, BO, 999); 
 ifail3 = AOM_save(home); 
 if (ifail3 == ITK_ok) 
 { 
  printf("\n\t***Item saved to home folder successfully***"); 
 } 
 else 
 { 
  EMH_ask_error_text(ifail3, &error3); 
  printf("\n\t%s", error3); 
 } 
 return 0; 
}

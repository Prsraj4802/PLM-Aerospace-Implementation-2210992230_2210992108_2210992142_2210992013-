// 11) Batch Utility – Print_BOM_line_item_id (level 1 childs only) 

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
#include<tccore/workspaceobject.h> 
#include<fclasses/tc_string.h> 
#include<sa/tcfile.h> 
#include<base_utils/Mem.h> 
#include<qry/qry.h> 
#include<ss/ss_const.h> 
#include<direct.h> 
#include<bom/bom.h>

// --- Program ---
#include"Header.h" 
 
int Print_BOM_line_item_id(char* id) 
{ 
 int ifail,count,i; 
 char *value_id,* value_name; 
 tag_t item, rev,* childs, window, bom_line; 
 
 ifail = ITEM_find_item(id, &item); 
 ifail = ITEM_find_revision(item, "A", &rev); 
 ifail = BOM_create_window(&window); 
 ifail = BOM_set_window_top_line(window, item, rev, NULLTAG, &bom_line); 
 ifail = BOM_line_ask_all_child_lines(bom_line, &count, &childs); 
 printf("\n\tParent item_id = %s", id); 
 printf("No. of childs to the given parent item = %d", count); 
 for ( i = 0; i < count; i++) 
 { 
  AOM_ask_value_string(childs[i], "bl_item_item_id", &value_id); 
  AOM_ask_value_string(childs[i], "bl_rev_object_name", &value_name); 
  printf("\n\t\titem_id = %s , Name = %s", value_id,value_name); 
 } 
 if (childs) 
  MEM_free(childs); 
 return 0; 
}

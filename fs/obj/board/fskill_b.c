inherit BULLETIN_BOARD;                                                         
#include <ansi.h>                                                               
void create()                                                                   
{                                                                               
set_name(HIR + "懲罰發表處" + NOR,({"means board","board"}));                         
set("location","/open/wiz/fsroom2");                                            
set("board_id","fskill_b");                                                     
set("long","這裏是提供巫師用來發表被懲罰玩家或巫師的地方,不希望你也在榜上");    
set("wiz_post",1);
setup();                                                                        
set("capacity",300);                                                            
  }                                                                             

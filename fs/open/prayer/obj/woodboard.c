#include <command.h>
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
     set_name("聖火教的令牌",({"wood board","board"}) );
     set_weight(1000);
     if( clonep() ) 
     set_default_object(__FILE__);
     else 
     {
     set("long",@LONG

     聖火教徒的信物之一, 此木牌是以檜木雕成, 並在其上刻以象徵
     聖火教的聖火圖樣!!除了做為聖火教門徒的辨認之外, 更可以將
     它握在手中做為徒手功擊的武器。
 
LONG);
     set("unit", "只");             
     set("value",60);
     set("no_sell",1);
     set("no_give",1);
     set("no_auc",1);
     set("no_drop",1);
     set("material","wood");
     }
     init_unarmed(15);
 
     setup();
}
void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  this_object()->set_name(""+(string)this_player()->name(1)+"的"HIC"令牌"NOR,({"wood board","board"}));
}

                   

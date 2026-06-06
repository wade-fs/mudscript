#include "/open/open.h"
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("殘缺不全的屍體", ({ "uncomplete-corpse","corpse" }) );
    set_weight(1000000);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "屍骨殘缺不全，看來生前受到極大的傷害。\n");
       set("unit", "具");
       set("value", 150);
       set("no_sell",1);
       set("no_auc",1);
       set("no_give",1);
       set("no_get",1);
      }
    setup();
}

int accept_object(object me,object ob)
{

me=this_player();
if(ob->query("id")!="incomplete_corpse's head")
tell_object(me,"結果什麼事也沒發生。\n");

if(me->query_temp("quest_corpse")==1)
{
message_vision("$N把$n給裝上去了。\n",me,ob);
tell_object(me,HIB"\n\n你彷彿聽到了一些聲音：遇到打不開的門，就祈禱吧...。\n"NOR);
me->set_temp("quest_corpse",2);
}

else
tell_object(me,"但你卻不知道要把"+ob->name()+"裝在哪？\n");
}

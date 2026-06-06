#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set("title","金刀門弟子");
set_name("鳳姑",({"fu-kou","fu","kou"}));
set("long","她是前黑牙聯殺手，但是背叛組織加入金刀門，目前被派來查探殺手總壇。\n");
set("gender","女性");
        set("attitude","friendly");
set("age",35);
set("int",30);
set("per",30);
set("str", 40);
set("con", 30);
set("force",400);
set("max_force",400);
set("combat_exp", 350000);
set_skill("force",30);
set_skill("dodge",75);
set_skill("parry",75);
setup();
add_money("gold",2);
}

int accept_kill(object who)
{
   say(HIY + "糟糕！被發現了！！\n" + NOR);
   setup();
   return 1;
}

void die()
{
   object head,killer;
 
   killer=query_temp("last_damage_from");
   if(killer->query_temp("kill_fu") != 1 )
   {
     message_vision(HIY + "可惡！居然會敗在你的手下,無法完成任務了\n" + NOR,this_object());
     message_vision("說完之後他就倒下了。。。。\n",this_object());
     head=new("/open/killer/obj/fu_head.c");
     head->move(this_object());
   }
   if (killer->query_temp("kill_fu") == 1)
   {
     message_vision(HIY + "居然為了一個香包，我會死在黑牙聯。。。含恨呀！\n" + NOR,this_object());
     message_vision("說完之後他就倒下了。。。。\n",this_object());
     head=new("/open/killer/obj/fu_page.c");
     head->move(this_object());
   }
   ::die();
}

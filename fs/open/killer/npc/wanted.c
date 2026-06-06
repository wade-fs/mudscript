#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set("title","黑牙聯前代兵器使");
set_name("完顏宏烈",({"hou-la","hou","la"}));
set("long","他是陷害柴榮叛變得背德小人，令人不恥，但你還是得小心一點。\n");
set("gender","男性");
        set("attitude","aggressive");
set("age",60);
set("int",30);
set("per",30);
set("str", 15);
set("con", 30);
set("force",400);
set("max_force",400);
set("combat_exp", 250000);
set_skill("force",50);
set_skill("dodge",50);
set_skill("parry",50);
setup();
add_money("gold",5);
}

int accept_kill(object who)
{
   say("小傢伙，你也想對付我？太自大了！！\n"
        +"我至少也是黑牙聯的兵器使呀！！!\n");
   setup();
   return 1;
}

void die()
{
   object head;
   object killer=query_temp("last_damage_from");
   
 if ( !present("menu",killer) )  //檢查玩家是否有殺人名單
{
   say(HIG + "可惡！天魔解體大法給你吧！\n" + NOR);
   message_vision(HIG + "他一溜煙的消失了，只留下那一本天魔解體大法....\n",this_object());
   message_vision("正當得意，取的天魔解體大法時，忽然一道氣勁來襲，\n讓你氣血翻騰，快昏倒了，在昏倒前聽到\n" + NOR,this_object());
   message_vision(HIY + "受了(魔氣殺之傷)你是保不住的，可惡的葉。。。\n" + NOR,this_object());
   killer->set_temp("hurt",1);
   killer->move("/open/killer/room/outr4.c");
   destruct(this_object());
}
 else
 {
  say(HIG + "為了殺人名單來殺我？..........可恨呀....居然會死於你的手上....含恨呀....\n" + NOR);
   head=new("/open/killer/obj/hou_head.c");
   head->move(this_object());
 }
::die();
}

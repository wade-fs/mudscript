
#include <ansi.h>
#include "/open/open.h"

inherit NPC;
string do_change();
string do_faceoff();
void create()
{
          set_name("徐大媽", ({ "mama shyu","mama","shyu" }) );
	set("gender", "女性" );
        set("age",45);
        set("str",35);
        set("cor",35);
	set("cps", 25);
	set("int", 15);
      set("long","徐大夫的夫人。\n");
	set("combat_exp",338);
	set("attitude", "peaceful");
        set("inquiry",([
        "變性":(: do_change :),
      "整容":(: do_faceoff :),
	"特殊服務":"僅此一家,別無分號,整容三千兩黃金,變性五千兩黃金。\n", ]));
             set("chat_chance", 20);
        set("chat_msg", ({
           "我們有「特殊服務」哦,參考看看啦....\n",
        }) );
	setup();
        carry_object("/obj/cloth")->wear();
}

int accept_fight(object me){
        return notify_fail("徐大媽叫道 : 夭壽喔!連我都想打啊?!\n");
}
string do_change(){ 
        object who;
        string str;
        who = this_player();
        str = "變性一次五千兩黃金，\n";
        if( !who->can_afford(50000000) ) {
        str += "錢不夠啊！那就對不起了。\n";
          return str;        }
       else {   who->pay_money(50000000);
                who->set_temp("change", 1);
                message_vision("$N付給徐大媽一筆錢。\n", who);
                  str += "嗯，變性手術請往北走。\n";
                return str;
}
}
string do_faceoff(){ 
         object who;
         string str;
         who = this_player();
str = "整容一次一千五百兩黃金，\n";
          if( !who->can_afford(15000000) ) {
          str += "錢不夠啊！那就對不起了。\n";

           return str;        }
        else {   who->pay_money(15000000);
                 who->set_temp("faceoff", 1);

                 message_vision("$N付給徐大媽一筆錢。\n", who);
                    str += "嗯，整容手術請往東走。\n";
               return str;
}}



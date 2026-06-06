#include "/open/open.h"
inherit NPC ;

string give_item(object me)
{
 me=this_player();
 me->set_temp("rain_0",1);
 return "這。。。我不敢講。你去魔教問靜柔姑姑，有關（天魔解體大法）的事情。\n";

}

string pass_room(object me)
{
 me=this_player();
 
 if (me->query_temp("key") != 1)
 {
   return "你不給我鑰匙，我怎麼開啟呢？。\n";

 }
 me->set_temp("key",2);
 return "想要進去？把鑰匙交給我吧！\n";

}

void create()
{
  object ob;
  set_name("少年",({"young"}));
  set("title", "看守");
  set("gender", "男性");
  set("class","killer");
  set("age",18);
  set("attitude", "killer");
  set("long", "他在此看守舊玩家所留下來的東西\t
你不要以為他是少年郎就好欺負,他可是葉秀殺的外甥哦，知道不少黑牙連的(往事)。
若沒有一定程度,要殺他是不可能....\n");
   set_skill("rain-throwing",30);
   map_skill("throwing","rain-throwing");
   set("inquiry",([
       "往事"    : "呵。。。你好可愛耶，那麼多往事我哪知道你要問哪一項(know)？\n",
       "霸雨式"  : "那天我看舅舅的受傷之處還有著特殊靈氣呢！！\n",
       "閻影匕首": "傳說，那是殺手的超高級技巧，只有內力達一定水準的人，才可以學。\n",
       "柴榮"    : "傳說他與冥蠱魔教有很深的(淵源)。\n",
       "專用兵器室" : (: pass_room :), 
       "天魔解體大法" : (: give_item :),
       "淵源"    : "傳說他好像拿走了，魔教的（天魔解體大法)。\n",
       ]));
   set("kee",600);
   set("max_kee",600);
   set("combat_exp",200000);
   setup();
    add_money("gold",12);
    carry_object("/open/killer/obj/s_pill.c");
    ob=carry_object("/open/killer/obj/lustar.c");
    ob->add_amount(199);
    ob->wield();
}

int accept_object (object me,object ob)
{
 if (ob->query ("id")== "key")
 {
   if (me->query_temp("key") != 2)
   {
     message_vision("你給我這個幹嘛！無聊！。\n",me);
     me->set_temp("key",0);
     return 0;
   }
   message_vision("好啦！鎖開啦！自己開門(open)啦！。\n",me);
   command("say 不過，我好無聊，陪我過招吧。。。");
   command("fight "+me->query("id"));
   me->set_temp("key",3);
   return 1;
 }
 return 0;
}

void init()
{
 add_action("do_know",({"know"}));
}

int do_know(object me)
{
 me=this_player();
 message_vision("這是青年的日記，但你不敢太仔細看，只略微看到了標題。\n",me);
 message_vision("七月四日，舅舅還是在回想(柴榮)叔叔的事。。。。\n",me);
 message_vision("八月十日，舅舅在和我對戰之時，使出殺手必殺招式(閻影匕首）\n",me);
 message_vision("十月十日，舅舅，一如往常在每月的十日外出，但今天回來時受了傷還喃喃的說（霸雨式）。\n",me);
 return 1;
}

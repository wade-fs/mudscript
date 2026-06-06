#include <ansi.h>
inherit NPC;

void create()
{
    set_name("小牧童",({"boy"}));
    set("long","一個可愛的小男孩！\n");
    set("gender","男性");
    set("attitude","friendly");
    set("age",10);
    set("no_kill",1);
    set("inquiry",([
        "登山客" : "那位叔叔人很好哦，送我一根棍子玩呢，這棍子上面好像有個狗的圖騰！\n",
        "打狗棒" : "是我手上這一支嗎？你想要呀？ (Yes or No)\n",
        "珍寶"   : "哦..我最想要金黃鳳凰的羽毛，好漂亮哦！\n",
        "金黃鳳凰" : "大鳥呀，只知道好像在直覺牠不可能生存的地方，也不曉得實際位置，等你拿來給我囉！\n",
                ]));
    setup();
}

void init()
{
  add_action("do_say","say");
}


int do_say(string arg,object me)
{
  me=this_player();
  if(!arg) return 0;
  if(me->query_temp("find_phoenix")==1)
    {command("say 吼～大叔，你很魯哦！"); return 1;}
  if(me->query_temp("find_pkdogstaff")!=1)
    { command("lazy "+me->query("id"));
      command("say 媽媽說不可以跟陌生人說話！"); return 1;
    }
  else {
  if (arg == "yes")
     {command("say 那你去幫我拿我最想要的珍寶來換吧！\n"); me->set_temp("find_phoenix",1);}
  else command("say 那你快走，不然我會被媽媽罵。\n");
     return 1;
     }
}

int accept_object(object me,object ob)
{
  object ob_name=ob->query("name"); 
  me=this_player();
  if(me->query_temp("ko_phoenix")==1 && (string)ob_name==HIY"鳳凰羽毛"NOR)
    {
      destruct (ob);
      command ("say 哇~~大叔你幫我拿到羽毛了耶！\n");
      command ("lean "+me->query("id"));
      command ("say 大叔，你等一下哦，我給你個東西！\n");
      call_out("badstaff",2,me);
      return 1;
    }
  else{
      command ("wuwu "+me->query("id"));
      command ("say 大叔你都騙我啦~~這不是我要的。\n");
      return 1;
      }
}

void badstaff(object me)
{
  object ob = new("/u/p/pana/obj/badstaff");
  me=this_player();
  message_vision("小牧童給了$N一把破爛的木杖！\n",me);
  ob -> move(me);
}



//排版與增加npc的eq 瀧山的相關線索 by blazakira 2011/8/31
//增加瀧山quest 狂龍訣的線索 by blazakira 2011/9/3

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string ask_crazydragon();

void create()
{
  set_name("任曉吟",({"sheauyin jen","sheauyin","jen"}));
  set("long","她是任正晴的女兒，任曉吟，年剛滿二十，清麗脫俗，看起來聰明伶
俐，雖是武者世家的女兒，但是不只精通武術還精通禮義，家中就屬
她最聰明乖巧。最近她有了煩惱。\n");
  set("gender","女性");
  set("class","fighter");
  set("nickname","任柔庭");
  set("combat_exp",200000);
  set("attitude","heroism");
  set("age",20);
  set("title","瀧山派第八代弟子");
  set("str",23);
  set("cor",20);
  set("cps",40);
  set("per",100);
  set("int",50);
  set("con",55);
  set("spi",70);
  set("kar",27);
  set("force",960);
  set("max_force",960);
  set("max_s_kee",1000);
  set("sec_kee","dragon");
  set("force_factor",20);
  set_skill("lungshan", 60);
  set_skill("dodge"   , 50);
  set_skill("haoforce", 60);
  set_skill("force"   , 70);
  set_skill("unarmed", 40);
  set_skill("parry", 30);
  set_skill("henma-steps",60);
  set_skill("fire-kee",50);
  map_skill("force", "haoforce");
  map_skill("unarmed", "lungshan");
  map_skill("dodge", "henma-steps");
  map_skill("parry", "fire-kee");
  set("inquiry",([
    "特別貢獻": "我也不清楚哪種任務才算是有貢獻？不過聽說瀧山裡的某處關著一位大壞人【葉狂】唷。\n",
    "葉狂"    : "我也是從我父親那裡聽來的，他是一位好恐怖的人呢。\n",
    "煩惱"    : (: ask_crazydragon :),
  ]));
  setup();
  carry_object("/open/wu/npc/obj/goldfinger.c")->wield();
  carry_object("/open/common/obj/sad_jade_wrists.c")->wear();
}

void init()
{
  add_action("do_nod","nod");
}

int do_nod()
{
  object me = this_player();
  if( me->query_temp("wu/ask_crazydragon") != 1 ) return 0;
  command("say 那麼 .... 就煩勞你了。");
  me->set_temp("wu/ask_crazydragon",2);
  return 1;
}

string ask_crazydragon()
{
  object me;
  me=this_player();
  if(me->query("combat_exp") < 2000000)
  {
   return "你這樣不行喔，好高騖遠可是不能在武道上走更遠的。\n";
  }
  else if(me->query("quests/crazydragon"))
  {
   return "高手！教教我如何使用狂龍訣。（大心\n";
  }
  if( me->query_temp("wu/ask_crazydragon") ) return 0;
  command("say 最近父親看起來好像有煩心事，但是卻不跟我說，讓我有些擔心。");
  command("say 不知道師弟是否可以幫我問問看？");
  me->set_temp("wu/ask_crazydragon",1);
  return "";
}

inherit NPC;
#include <ansi.h>
#include "/open/open.h"
inherit F_MASTER;
string happy();


void create()
{
set_name("年獸",({"year beast","year","beast"}));
set("long","
傳說中的年獸, 跟他打聲招呼吧.
\n");
  set("gender","男性"); 
  set("class","killer");
  set("attitude","heroism");
  set("age",999);
  set("max_kee",900000);
  set("kee",900000);
  set("max_force",20000);
  set("force",20000);
  set("force_factor",10);
  set("combat_exp",1500000);
  set_skill("dodge",5000);
  set_skill("move",100);
  set_skill("force",100);
  set_skill("parry",5000);
  set("inquiry",([
"新年快樂" : (: happy :),
]));

setup();
add_money("gold",10);
}

int accept_kill(object who)
{
  command("say 拿鞭炮嚇我比較快......");
  return 1;
}
string happy()
{
 object ob;
 object me;
 object bag;
 ob=this_object();
 me=this_player();
 if (me->query("combat_exp") < 100000 ) {return "你江湖歷練還不夠, 不能給你紅包!!";}
 if (me->query("/quests/2004-year/")== 1 ) {return "拿過紅包不能再拿喔!!";}
 if (me->query("race")!= "人類" ) {return "是人類才過年啦!!";}
 command("look "+me->query("id"));
 me->set("quests/2004-year",1);
 bag=new("/open/killer/obj/redbag");
 bag->set("no_drop",1);
 bag->set("no_give",1);
 bag->set("no_sell",1);
 bag->move(me);
 return "原來是"+me->query("name")+"啊....大過年還在這裡奮鬥, 真是辛苦啊...給你紅包作為獎勵!!";
}

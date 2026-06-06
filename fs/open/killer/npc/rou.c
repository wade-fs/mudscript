//排版 by blazakira 2011/10/8

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string do_trial();

int accept_object (object me,object ob)
{
  object ob2;

  if (me->query_temp("rain_3") != 1)
  {
    command ("say 神經病，你給我這個幹嘛！\n");
    return 0;
  }
  if(ob->query("id") == "low_letter") 
  {
    message_vision(" 柴榮將信收下來，將信拆開，仔細閱\讀。\n",me);
    message_vision(" 看完信後，柴榮將信受入懷中。\n",me);
    command("say 很好，你想找天魔解體大法，我就告訴你吧！\n");
    command("say 在總壇一樓，宿舍那裡有一個往地下一樓的密道。\n");
    command("say 有一個叛徒在那裡，天魔解體大法就是被他取走。\n");
    destruct(ob);
    me->set_temp("rain_4",1);
    return 1;
  }
  if(ob->query("id") == "evil_god") 
  {
    if (me->query_temp("rain_4") != 1)
    {
      command ("say 投機取巧，請別人拿！作弊！你給我滾！看掌——\n");
      message_vision(" $N被柴榮一掌打飛，不知去向。\n",me);
      me->move("/open/killer/home/firstrm.c");
      destruct(ob);
      return 0;
    }
    message_vision(" 柴榮仔細閱\讀了天魔解體大法之後，仰天長嘯——\n",me);
    command("shout 太好了，我們殺手後繼有人，我就傳你魔氣殺吧！！\n");
    command("say 「魔氣殺」為殺手的超級攻擊技巧，這是將天魔解體大法融合在霸雨式中，\n魔氣殺本身所特別之處在於特殊的內力使用法（天魔解體大法）\n所以可以運用於任何武器之上，威力並不會下降。\n指令：perform throwing.manakee\n");
    if (me->query("quest/memoey") != 1)
      me->set("title",HIG + "黑牙聯超上級殺手" + NOR);
    destruct(ob);
    me->set("quest/rain",1);
    me->set_temp("rain_4",0);
    return 1;
  }
  return 0;
}

void create()
{
  set_name("柴榮",({"chil-rou","rou"}));
  set("long","傳說此人曾為魔教的一員，後來因故加入黑牙聯，又因故脫離。\n"+
    "\t因此擅長兩家之長，又會殺手密技--霸雨式。\n");
  set("gender","男性");
  set("class","poisoner");
  set("nickname", HIR + "神秘殺手" + NOR);
  set("combat_exp",1000000);
  set("attitude","heroism");
  set("age",27);
  set("str", 50);
  set("cor", 35);
  set("cps", 18);
  set("per", 30);
  set("int", 20);
  set("force",1000);
  set("max_force",800);
  set_skill("move",90);
  set_skill("force",60);
  set_skill("dodge",80);
  set_skill("parry",80);
  set_skill("poison",80);
  set_skill("whip",40);
  set_skill("throwing",100);
  set_skill("rain-throwing",110);
  set_skill("poisonforce",40);
  set("force_factor",10);
  set_skill("coldpoison",80);
  set_skill("nine-steps",80);
  map_skill("throwing","rain-throwing");
  map_skill("dodge","nine-steps");
  map_skill("move","nine-steps");
  set_skill("ming-snake",60);
  set("inquiry",([
    "閻影匕首" : "葉秀殺，叫你來的嗎？可以，通過(試煉)再說吧。\n",
    "試煉" : (: do_trial :),
    "莊靜柔"   : "我對不起她。\n",
  ]));
  setup();
  carry_object("/open/killer/obj/lustar")->set_amount(100);
  add_money("gold",20);
}

string do_trial()
{
  object me = this_player();

  if(me->query("quest/rain") == 1)
  {
    command("say 有志氣！不過試煉要很久哦……\n");
    // me->move("/open/killer/trail/beginrm.c");
    return"say 唉…此謎還沒做好，你請回吧。\n";
  }
  command("sm "+me->query("id"));
  return "哼！不知道。\n";
}

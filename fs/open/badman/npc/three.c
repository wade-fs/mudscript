#include <ansi.h>

inherit NPC;
string do_ask();

void greeting(object who);

void create()
{
      set("title","三姑");
      set_name("胖婦人",({"fat woman","fat","woman"}) );
      set("long",@LONG
 一個身材胖碩的婦人，圍著一條油膩膩的圍裙，正坐在椅上道人長短；其嗓門和潑辣
，在這條街上可說是無人能出其右。沒事的話最好離她遠些。
LONG
      );
      set("age",38);
      set("attitude","peaceful");
      set("gender","女性");

      set_skill("dodge",25);
      set_skill("unarmed",30);
      set_skill("move",30);
      set("combat_exp",2000);

      set("chat_chance",4);
      set("chat_msg",({
      "胖婦人口沫橫飛的說:最近那個明月啊,聽說被女朋友甩了耶。呵.....\n",
      "胖婦人興高采烈的說:我家的大寶啊,是越來越懂事囉。呵.....\n",
      "胖婦人幸災樂禍的說:聽說啊,隔壁的王太太和別人跑了耶....\n",
      "胖婦人神氣活現的說:杜殺的左手啊,好像就是被第一神劍燕南天給砍斷的耶....\n",
      }) );
      set("inquiry",([
      "運勢"   : (: do_ask :),
      "運勢加強" : (: do_ask :),
      "加強運勢" : (: do_ask :),
      ]));

      setup();

      carry_object("/obj/cloth")->wear();
      add_money("silver",3);
}

int accept_fight(object who)
{
      message_vision("胖婦人冷冷的瞟了$N一眼。\n",who);
      command ("say 怎麼?你這點三腳貓的功\夫也想和老娘動手?尋死麼?\n");
      return 1;
}

void init()
{
      object who;
      ::init();
      if( interactive( who=this_player()) && !is_fighting() ) {
        remove_call_out("greeting");
        call_out("greeting",1,who);
      }
}

void greeting(object who)
{
      if( !who||environment(who)!=environment() ) return;
      switch (random(2)) {
      case 0:
      say("胖婦人罵道:怎麼連聊個天也都有你他媽的那麼多人來來去去。\n");
      break;
      case 1: 
      say("胖婦人瞪道:喂!"+RANK_D->query_rude(who)+",沒事的話就給老娘滾遠些,別礙著老娘聊天。\n");
      break;
      }
}

string do_ask()
{
  int me;
  object who = this_player();
    if(who->query_temp("marks/karup")!=1)
  {
   return "你在說啥啊?\n";
  }
  else
  {
   who->set_temp("marks/karup2",1);
   return "在惡人谷中的某間破廟好像有會發光的東西....\n";
  }
}

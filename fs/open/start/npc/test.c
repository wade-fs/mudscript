//woman.c
//補充線索 方便新手解謎 by blazakira 2010/12/24

#include "../start.h"
inherit NPC;
string give_stone();

void create()
{
  set_name("年輕農婦",({"woman"}));
  set("long","一個平凡的農家婦女，但似乎在煩惱著什麼\n,你可以問問她有什麼須要幫忙(trouble)的。\n");
  set("gender","女性");
  set("age", 20);
  set("combat_exp",1000);
  set("inquiry",([
    "trouble":"我好煩喔, 我前幾天在農地裡挖土時挖到一樣珍品\n",
    "珍品":"我撿到一顆寶石, 你可以幫我還給原主嗎?\n",
    "寶石":"看它上面的龍紋刻印, 一定是某位高官的物品~\n",
    "紅寶石":(: give_stone :),
    "red stone":(: give_stone :),
  ]));

  setup();
  carry_object(S_OBJ"apron")->wear();
}

string give_stone()
{
  object who, item;
  who = this_player();

  if( who->query("quests/stone") || who->query_temp("stone")==1 )
    return "你不是已經把紅寶石拿走了嗎？\n";
  else if( who->query_temp("紅寶石")==2 ) {
    item = new(S_OBJ"stone");
    item->move(who);
    message_vision("婦女給$N一顆紅寶石。\n", who);
    who->set_temp("stone", 1);
    return"真是的,還好我又在路上撿到了,再幫我還給主人喔！\n";
  }
  else {
    item = new(S_OBJ"stone");
    item->move(who);
    printf("婦女給%s一顆%s。\n",
      who->query("name"),item->short() );
    who->set_temp("stone", 1);
    return "麻煩你將紅寶石物歸原主了, 主人想必是很著急的。\n";
  }
}

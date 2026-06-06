// any.c by anmy 97/11/17
//增加新手quest 尋找武林盟主的下落 by blazakira 2011/4/2
//起始npc改為any 其內容為探訪各大門派的上層人士尋找線索 由於有雙色字的存在 因此主要以沒有雙色字的npc為主要線索提供者
//探訪一次 add_temp一次 最後找到盟主npc 再結算獎勵 獎勵為金錢與pot 不給經驗
//額外再給一件水晶寶衣? 新手時期才能使用好了 也就是判斷使用者的exp為使用條件之一 不補發
//在指令quest的額外敘述中 註明線索 其關鍵字為 武林盟主 跟 尋找（暫定
//從本npc知道武林盟主下落不明開始 並做第一次起始mark
//此後依據此mark 做線索提供的判斷標準
//以門派做區別 先判斷是否為平民 再判斷是否與給線索的npc為同一門派 最後才是其他門派
//邪派除了本門弟子外大多不給予線索 以扯開話題為主
//正派會給線索 本門弟子的話 則會給第二段線索
//中立則以擦邊球般的線索為主
//這quest故事是 盟主繼位 為了抵抗外患而號招群雄（這句話也可以當作置身事外的門派給予的線索） 這是替忍者島做的鋪陳
//然而道高一尺 魔高一丈 在廣發英雄帖（？）的同時 就被人暗殺了
//發英雄帖的原因是 盟主在某個因緣際會下 發現忍者島的陰謀 或者說 在探查線索時 某個門派的首領被暗殺之類的
//在newhand的npc中 額外做quest 指引線索 讓玩家找到本npc any吧 懶得將起始npc 調整到newhand的那npc上 因為要調整故事的線索敘述

#include <ansi.h>
//#include "../start.h"
inherit NPC;

string ask_leader();
string ask_leader2();
string ask_leader3();
string ask_ball()
{
  if(!this_player()->query_temp("swordtime"))
  {
    return ("對不起﹐你問的事我實在沒有印象。");
  }
  else
  {
    if (this_player()->query("class")=="scholar"&&this_player()->query_temp("swordquest/findball")==4)
    {
      this_player()->set_temp("swordquest/findball",5);
      return ("在幾年前﹐有位美麗的俠女拿到皇城請皇上保管﹐但是在俠女走後半年﹐便遭人偷走了﹐現在皇上提都不敢提這件事。\n");
    }
    else return ("對不起﹐你問的事我實在沒有印象。");
  }
}

void create()
{
  set_name("幽嵐", ({"beauty any","any","beauty" }) );
  set("gender", "女性");
  set("nickname", HIC + "馨嵐公主" + NOR);
  set("age", 20);
  set("long","你看到一個清秀的女孩出現在你面前，她長得絕頂美麗，還帶著一種不同於其他人的氣質，\n她似乎失落了一些東西。\n");
  set("per", 40);
  set("str", 25);
  set("con", 20);
  set("combat_exp", 10000);

  set("chat_chance", 5);
  set("chat_msg", ({
    "幽嵐對著你微笑著。\n",
    "幽嵐不斷地左顧右盼，似乎在找尋著什麼東西...\n",
  }) );
  set("inquiry",([
    "麗玉蝶蘭晶珠" : (:ask_ball:),
    "武林盟主"     : (:ask_leader:),
    "怎麼辦"       : (:ask_leader2:),
    "大亂"         : (:ask_leader2:),
    "各大門派"     : (:ask_leader3:),
  ]));

  setup();
  carry_object("/obj/cloth")->wear();
}

void init() {
//  set_heart_beat(1); //這樣才會不斷的走。
//  ::init();
}

int accept_fight(object me)
{
  return notify_fail("幽嵐公主說：這位"+RANK_D->query_respect(me)+"別開我玩笑了好嗎？\n");
}

int accept_object(object who , object item)
{
  if( item->query("id")=="stone" ) {
    tell_object(who,"幽嵐公主開心的笑著：辛苦你了！謝謝你幫我找回寶石，謝謝～\n");
    if( !who->query("quests/stone") && who->query_temp("stone")==1 )
    {
      who->add("combat_exp",1000);
      tell_object(who,HIY + "你完成了失落的寶石之謎！\n" + NOR);
      tell_object(who,HIC + "你的經驗增加了 :p\n" + NOR);
      who->set("quests/stone", 1);
    }
  }
}

string ask_leader()
{
  object me=this_player(),ob=this_object(),obj;
  int k=me->query_temp("ask_leader/gift");
  if( !me->query("quests/leader") ) {
    if( k > 5 )
    {
      command("say 謝謝"+me->query("name")+"大俠你幫本公主收集到這消息，我要回去告訴父皇。\n" + NOR + "(俏皮地說完就蹦蹦跳跳地跑回皇城裡。)");
      tell_object(me,HIY + "你完成了尋找武林盟主的下落！\n" + NOR);
      tell_object(me,HIC + "你的經驗與潛能增加了 :p\n" + NOR);
      me->add("combat_exp",k*100);
      me->add("potential",k*50);
      if( me->query("combat_exp") < 100000 ) {
        obj=new("/autoload/wind-rain/mark.c");
        obj->move(me);
        command("say 對了！對了～\n" + NOR + "(雀躍地跑回來，像是想起了什麼事。)");
        command("say 這片是小時候到風雨樓遊玩時所使用的通行證明，就暫時交給你使用，\n"+
          "                  或許\你能到風雨樓裡磨練一下自己的武藝。");
        message("vision",sprintf("%s給你一%s%s。\n",ob->name(),obj->query("unit"),obj->name()),me );
        message("vision",sprintf("%s給%s一%s%s。\n",ob->name(),
          me->name(),obj->query("unit"),obj->name()),environment(me),({me,ob}) );
      }
      destruct(ob);
      me->set("quests/leader",1); //任務結束
      return "";
    }
    else if( !me->query_temp("ask_leader/start") )
    {
      me->set_temp("ask_leader/start",1); //任務開始
      tell_object(me,HIC + "幽嵐公主憂心著說：怎麼辦？怎麼辦？武林就要大亂了…\n" + NOR);
      return "";
    }
  }
  if(random(2))
    command("smile "+me->query("id"));
  else
    command("giggle "+me->query("id"));
  return "";
}

string ask_leader2()
{
  object me=this_player();
  if(me->query_temp("ask_leader/start") != 1)
  {
    return 0;
  }
  tell_object(me,HIC + "幽嵐公主對著你說：\n"+
  "　　詳細情況我也不清楚，但是據說現任盟主被不明人士所暗殺，至此下落不明，也許\各大\n"+
  "　　門派掌握某些線索。\n\n" + NOR);
  me->set_temp("ask_leader/start",2);
  return "";
}

string ask_leader3()
{
  object me=this_player();
  if(me->query_temp("ask_leader/start")!=2)
  {
    return 0;
  }
  tell_object(me,HIC + "幽嵐公主對著你說：\n"+
  "　　有些消息不一定由門主所掌握，但是還是集中在上層人士手中。由於我不能隨意離開京\n"+
  "　　城，但是我想為了百姓和平的日子盡些心力，能麻煩你幫我到各門派詢問武林盟主的下\n"+
  "　　落嗎？我希望避免各大門派之間的內耗，使得外人入侵本土，使百姓生靈塗炭。\n"+
  "　　\n" + NOR + "(拜訪各門派的路徑，請參詳help 路徑)\n\n");
  me->set_temp("ask_leader/start",3);
  return "";
}

//增加查看所殺死的殭屍數量查詢 by blazakira 2011/8/27

#include <ansi.h>
inherit NPC;

string ask_enter();
string ask_zombie_king();
string ask_hurt();
string ask_zombie_kill();

void create()
{
  seteuid(getuid());
  set_name("林正英",({"taoist lin","lin","taoist"}));
  set("long",@LONG
他是一名正氣凜然的道士，通常身旁通常會帶著兩個做事少根筋的徒弟一起對抗妖魔鬼怪。
但他似乎像守衛著這裡，不隨便讓人進入(enter)。
LONG);
  set("gender","男性");
  set("title",HIW"殭屍道長"NOR);
  set("combat_exp", 1000000);
  set("attitude","friendly");
  set("age",62);
  set("force",5000);
  set("max_force",5000);
  set("kee",1000);
  set("max_kee",1000);
  set("force_factor",30);
  set("no_get",1);
  set("inquiry",([
    "enter"    : (: ask_enter :),
    "殭屍王"   : (: ask_zombie_king:),
    "刀槍不入" : (: ask_hurt :),
    "殭屍"     : (: ask_zombie_kill:),
    "回去"     : "我徒兒還困在裡面，我不能放下他們不管",
    "陸清風"   : "我徒兒還被困在這裡面，我實在是不能放下他們不管",
    "控屍術"   : "我現在沒有心情你說這些，你得先把裡面的殭屍王幹掉，並且救出我徒弟。",
    "控屍之術" : "我現在沒有心情你說這些，你得先把裡面的殭屍王幹掉，並且救出我徒弟。",
    "徒兒"     : "他們被殭屍王困在裡面，我一個人的力量救不出來",
    "黑狗血"   : "就去殺黑色毛皮的狗啊，就有黑狗血了。",
    "墨斗線"   : "就去買墨斗線啊。",
    "糯米"     : "去蒙古大軍的廚房就有得偷，不過一切都要小心。",
    "throw"    : "東西準備好就可以丟向殭屍了。",
  ]));
  setup();
}

void init()
{
  object obj;
  ::init();
  obj = previous_object();
  if(obj->query_temp("control") == 7)
  {
    command("spank "+obj->query("id"));
    command("say 太好了，利用我徒弟尚未恢復的時候，我就教你控屍大法，就可以協助幫忙趕屍了。\n");
    tell_object(obj,HIR"你習得江西控屍大法。\n"NOR);
    obj->set("quest/control",1);
    obj->set("spells/control/level",1);
  }
}

int accept_object(object me, object obj)
{
  if(me->query_temp("control") == 5){
    if(obj->query("id") == "zombie king head" && obj->query("control")) {
      object z;
      me->set_temp("control",6);
      destruct(obj);
      command("say 太好了，這果然是殭屍王的頭，這樣我二個弟子也有救了。");
      command("say 我先留下來幫忙照顧我弟子，你先幫我把殭屍趕去蜀中城的鐵舖親人，讓他安心下葬，謝謝。");
      command("say 來吧，我先送你回去中央驛站。");
      me->move("/open/trans/room/room4");
      z = new(__DIR__"/zombie.c");
      z->set("owner",me);
      z->move("/open/trans/room/room4.c");
      z->set_leader(me);
    }
  }
  return 1;
}

string ask_enter()
{
  object me = this_player();
  object npc;
  if(me->query_temp("control") &&
      !me->query_temp("control_dog") &&
      !me->query_temp("control_rice"))
    return "你還沒準備好，這樣扺抗不了殭屍王的攻擊的。";
  else if(me->query_temp("control") == 3 ) 
    me->set_temp("control",4);
  if((time() - me->query_temp("enter_time")) < 60*5 )
    return "你才剛進去過，身上的殭屍氣吸太多，需要稍事休息。\n";
  if(me->query_temp("not_robot") < time()) 
    return "你確定要進去嘛？ 你身上並沒有任何可以防止殭屍的正義之氣，千萬不能進去啊！。";
  tell_object(me, HIC"林正英說道：哎呀，這麼有勇氣，哪就進去挑戰看看吧，不過如果沒有帶著任何符咒的\n"+
    "\t話，你千萬不要再往裡面走，因為裡面的殭屍王已殺死了不少武林中人了。\n"NOR);
  message_vision(HIR"突然五行八卦隨即轉換，殭屍洞裡的路徑全部更換。\n"NOR,me);
  for(int i = i ; i<= 10; i ++)
  {
    tell_room(sprintf(resolve_path(__DIR__,"../room%02d.c"),i),
        HIR"突然五行八卦隨即轉換，殭屍洞裡的路徑全部更換。\n"NOR);
  }
  foreach(object obj in children(__DIR__+"zombie") )
  {
    if(obj->query("owner") == me) npc = obj;
  }
  load_object(resolve_path(__DIR__,"../enter.c"))->random_road();
  if(!npc)  npc = new(__DIR__+"zombie");
  npc->move(load_object(sprintf(resolve_path(__DIR__,"../room%02d.c"),random(10))));
  npc->set("owner",me);
  npc->set("nickname",npc->query("owner")->name()+"的");
  me->move(resolve_path(__DIR__,"../room01.c"));
  me->set_temp("enter_time",time());
  return "你還真有勇氣啊，一切路上小心。";
}

string ask_zombie_king()
{
  if(this_player()->query_temp("control") > 1) {
    return "還不快去把殭屍王殺掉。";
  }
  if(this_player()->query_temp("control") == 1) {
    this_player()->set_temp("control",2);
  }
  return "殭屍王刀槍不入，任何方法都傷害不了他，除非你要準備好東西再進去打他。";
}

string ask_hurt()
{
  if(this_player()->query_temp("control") == 2)
  {
    this_player()->set_temp("control",3);
    return "你可以準備好黑狗血、墨斗線和糯米，這三項東西往殭屍王丟(throw)去，就可以克制住殭屍王的刀槍不入。";
  }
  if(this_player()->query_temp("control") < 3) {
    return "你還是不要去送死的好。";
  }
  if(this_player()->query_temp("control") > 2) {
    return "快去準備準備吧。";
  }
}

string ask_zombie_kill()
{
  if(this_player()->query("zombie_kill"))
  {
    return "你打倒了共有"+HIY+this_player()->query("zombie_kill")+CYN+"隻殭屍。"NOR;
  }
  return "你還沒殺過任何的殭屍吧。";
}

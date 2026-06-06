//修正會把recall.up炸掉的問題 by blazakira 2013/9/8

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  seteuid(getuid());
  set("short","密室");
  set("long", @LONG

你走進一間陰暗潮濕的小房間，其氣味難聞難受有如死屍般，等你五
官慢慢習慣黑暗後，你看見在這兒有一張床、一張桌子、四面牆(wall)和
一個用來嗯嗯的茅坑，但到處都結滿了蜘蛛絲。你赫然發覺在西邊牆角的
小窗子(window)旁邊有個人被用鐵門鎖在那裡。
LONG
);
  set("no_fight",1);
  set("light_up", 1);
  set("no_transmit",1);
  set("no_auc",1);
  set("item_desc", ([ /* sizeof() == 2 */
    "window" : "    一個木框小窗，你由窗口往外看去，發現外下頭正對一個水池，你不
禁突發奇想，想由這兒跳下去（jump）是不是比較快下到一樓！？
",
    "wall" : " 修羅心法之口訣 (words)
             修羅鬥氣乃修羅心法之絕學﹐學之有成者(read words)可將內力聚結﹐轉
             而發出數倍內勁﹐是我冥殿至高之絕學。    perform fiendforce.fight
",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/tendo/room/tower/npc/fiend.c" : 1,
  ]));
  setup();
}

void init()
{
  add_action("do_read","read");
  add_action("do_jump","jump");
  add_action("free_fiend","free");
}

int do_read(string str)
{
  object me=this_player();
  if(str!="words") {
    tell_object(me,"你想要讀什麼?\n");
    return -1;
  }

  if( !me->query_temp("free_fiend") )
  {
    tell_object(me,"冥殿修羅說：「先釋放了我才告訴你這口訣，否則你永遠也得不到！」\n");
    return 1;
  } else {
    if(me->query_skill("fiendforce",1) > 1)
    {
      tell_object(me,"你早就已經會修羅心法了。\n");
      return -1;
    } else {
      tell_object(me,"你照著牆上的口訣練了一遍，氣運一周天，你學會了修羅心法。\n");
      me->set_skill("fiendforce",1);
      return 1;
    }
  }
}

int do_jump()
{
  object who;
  who = this_player();

  who->move("/open/center/room/inn");
  tell_room(this_object(),"你只看到一道閃光,忽的一聲，人已跳了下去。\n");
  message("system", HIW"\n\t武林之中傳來一道消息 : "HIY""+this_player()->name()+""HIW"輕輕鬆鬆地闖過了"HIR"鎖妖塔"HIW" !!\n"NOR,users());
  return 1;
}

int free_fiend(string str)
{
  object ob,ob1;
  ob=this_player();
  if(!present("fiend",environment(ob)))
    return notify_fail("人又不在，你放什麼。\n");
  if(str != "fiend")
    return notify_fail("你要釋放誰呀。\n");
  if( !ob->query_temp("ko_towerking") )
    return notify_fail("少了鎮塔明王的一點靈光，是無法釋放冥殿修羅的！。\n");
  if( ob->query("force") > 10000)
  {
    message_vision(HIC"$N運起全身的內力打破了那道"HIW"鐵門"HIC"。\n"NOR,ob);
    ob->set_temp("free_fiend",1);
    ob->delete_temp("ko_towerking");
    ob1=present("fiend",this_object());
    destruct(ob1);
    call_out("msg1",3,ob);
  }
  else
  {
    message_vision(HIR"$N運起內力想要打破那道"HIW"鐵門"HIR"，由於內力不足被鐵門上的陰勁反彈而受傷。\n"NOR,ob);
    ob->add("kee",-200);
  }
  return 1;
}

int msg1(object ob)
{
  message_vision(HIR"\n只見冥殿修羅運起內力，突然整個牆面炸了開來。\n"NOR,ob);
  call_out("msg2",3,ob);
  return 1;
}

int msg2(object ob)
{
  object ob1;
  message_vision(HIW"\n冥殿修羅道：小夥子﹐感謝啦﹗\n"NOR,ob);
  message_vision(HIW"\n冥殿修羅道一個縱身﹐往窗戶那兒跳下﹐身影旋即消失在你的面前。\n"NOR,ob);
  set("exits/up","/open/snow/room/back");
  message("mud","天空霎時烏雲密佈...\n",users());
  message("mud","一陣狂吼聲突然傳遍武林各個角落﹗﹗﹗\n",users());
  message("mud","冥殿修羅將抑鬱的真氣﹐整個爆發出來﹐吼道﹕\n
                 武林的人給我聽著﹐今天由於"+ob->query("name")+"的幫助﹐我冥殿修羅得以重現江湖﹐
                 一切新仇舊恨﹐總算可以來個了結啦﹗﹗﹗\n
                 哈﹗哈﹗哈﹗哈﹗哈﹗\n
                 天道派和五百年前武林中自羿為正道人士的老賊及他們的弟子﹐
                 等著我血洗武林吧﹗\n\n",users());
  call_out("msg3",3,ob);
  return 1;
}

int msg3(object ob)
{
  new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road4.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road4.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road2.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road2.c");
  new("/open/tendo/room/tower/npc/monster_w")->move("/open/center/room/road1.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road3.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/center/room/road3.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road3.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road3.c");
  new("/open/tendo/room/tower/npc/snake_w")->move("/open/gsword/room/su3.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/gsword/room/sushop.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/gsword/room/sushop.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/capital/room/r70.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/capital/room/r70.c");
  new("/open/tendo/room/tower/npc/yama_w")->move("/open/main/room/r19.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/r12.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/r12.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/r10.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/r10.c");
  new("/open/tendo/room/tower/npc/plaguer_w")->move("/open/main/room/f11.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/f12.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/main/room/f12.c");
  new("/open/tendo/room/tower/npc/villain_w")->move("/open/ping/room/road4.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road5.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road5.c");
  new("/open/tendo/room/tower/npc/chieftain_w")->move("/open/ping/room/road6.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road10.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/road10.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/soldier2.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/soldier2.c");
  new("/open/tendo/room/tower/npc/goblin_w")->move("/open/ping/room/soldier1.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/inn.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/ping/room/inn.c");
  new("/open/tendo/room/tower/npc/butcher_w")->move("/open/wu/room/school1.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/wu/room/school1.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t03.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t03.c");
  new("/open/tendo/room/tower/npc/fiend_w")->move("/open/tendo/room/t03.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t04.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t04.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t02.c");
  new("/open/tendo/room/tower/npc/genies")->move("/open/tendo/room/t02.c");

  message("mud",HIG"\n\n鎖妖塔頂轟的一聲并出了逾千條的青光，像流星飛逝般撒落人間....\n"NOR,users());
  message("mud",HIR"\n眾妖齊道:\n
                  我們終於重獲自由，此後將誓死追隨修羅
                       剷平人間，重建魔界黯黑力量
                    完成焚天大王五百年前給予的使命....\n"NOR,users());
  call_out("msg4",3,ob);
  return 1;
}

int msg4(object ob)
{
  message("mud","陸清風嘆道﹕\n
                難道五百年前腥風血雨的慘劇又要再次重演嗎﹖
                武林各大派﹐今天又到了要團結一致的時候了﹗
                大家齊心協力消滅冥殿修羅跟他的餘黨﹗\n\n",users());
  message("mud","陸清風縱聲長嘯﹕\n
                我以天道派掌門之位﹐請求武林各門派﹐今後見到修羅及其黨羽者－\n
                格殺勿論﹗﹗﹗\n
                且今日下令我天道派弟子追殺禍首"+ob->query("name")+"﹗﹗﹗\n",users());
  call_out("msg5",30,ob);
  return 1;
}

int msg5(object ob)
{
  object room;
//  room = environment(ob);
//  room->delete("exits/up");
  this_object()->delete("exits/up"); //避免玩家在跑道這判斷前跑掉 造成誤刪其他房間而調整 by blazakira 2013/9/8
  message_vision(HIW"\n冥殿修羅炸開的一條通道崩毀了﹗\n"NOR,ob);
  return 1;
}

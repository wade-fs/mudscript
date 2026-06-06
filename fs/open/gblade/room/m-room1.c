inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
        seteuid(getuid());
        set("short",CYN"地牢"NOR);
        set("long", @LONG

你走進一間陰暗潮濕的小房間，其氣味難聞難受有如死屍般，等你五
官慢慢習慣黑暗後，你赫然發覺有個人被鎖在這裡，他四肢被骨鍊鎖
住，琵琶骨也被骨鍊貫穿，他低著頭動也不動，不知他是死是活。

LONG
        );
        set("light_up", 1);
        set("no_transmit",1);
        set("no_auc",1);
        set("objects", ([ /* sizeof() == 1 */
            "/open/snow/obj/sa1.c" : 1,
]));
set("exits",([
"out":"/open/trans/room/room4",
]));
  setup();
}
void init()
{
 add_action("free_sa","free");
}
int free_sa(string str)
{
  object ob,ob1;
  ob=this_player();
  if(!present("sa",environment(ob)))
    return notify_fail("人又不在，你放什麼。\n");
  if(str != "sa")
    return notify_fail("你要釋放誰呀。\n");
  if( ob->query("force") > 1500)
  {
message_vision(HIW"$N運起全身內力扯斷"HIC"魔血骨鍊"HIW"。\n"NOR,ob);
  ob1=present("sa",this_object());
  destruct(ob1);
  call_out("msg1",3,ob);
  }
  else
  {
message_vision(HIW"$N運起內力想要扯斷"HIC"魔血骨鍊"HIW"，由於內力不足被骨鍊上的陰氣所侵。\n"NOR,ob);
   ob->add("kee",-200);
  }
return 1;
}
int msg1(object ob)
{
message_vision(HIR"\n只見獨孤嵊運起內力，眼睛發出噬人的紅光。\n"NOR,ob);
 call_out("msg2",3,ob);
  return 1;
}
int msg2(object ob)
{
  object ob1;
message_vision(HIW"\n獨孤嵊道：年輕人謝謝你啦。\n"NOR,ob);
message_vision(HIW"\n獨孤嵊雙手向上一擊，轟的一聲，地牢上方被打出一個大洞，輕身飛躍出去。\n"NOR,ob);
set("exits/up","/open/snow/room/back");
message("mud",HIC"\n獨孤嵊笑道："HIW"哈哈哈，我終於自由了，徒兒們跟我一起去剷平魔刀吧。\n"NOR,users());
  call_out("msg3",3,ob);
  return 1;
}
int msg3(object ob)
{
 new("/open/snow/npc/fbandit")->move("/open/gsword/room/su3");
 new("/open/snow/npc/fbandit")->move("/open/gsword/room/su3");
 new("/open/snow/npc/fbandit")->move("/open/gsword/room/su3");
 new("/open/snow/npc/fbandit")->move("/open/gsword/room/sushop");
 new("/open/snow/npc/fbandit")->move("/open/gsword/room/sushop");
 new("/open/snow/npc/fbandit")->move("/open/ping/room/road4");
 new("/open/snow/npc/fbandit")->move("/open/ping/room/road4");
 new("/open/snow/npc/fbandit")->move("/open/ping/room/road4");
 new("/open/snow/npc/fbandit")->move("/open/ping/room/road3");
 new("/open/snow/npc/fbandit")->move("/open/ping/room/road3");
 new("/open/snow/npc/fbandit")->move("/open/gblade/mroom/room1");
 new("/open/snow/npc/fbandit")->move("/open/gblade/mroom/room1");
 new("/open/snow/npc/fbandit")->move("/open/gblade/mroom/room1");
 new("/open/snow/npc/fbandit")->move("/open/gblade/mroom/room9");
 new("/open/snow/npc/fbandit")->move("/open/gblade/mroom/room9");
 new("/open/snow/npc/fbandit")->move("/open/gblade/mroom/room9");
 new("/open/snow/npc/fbandit")->move("/open/gblade/room/secret");
 new("/open/snow/npc/fbandit")->move("/open/snow/room/back");
 new("/open/snow/npc/fbandit")->move("/open/snow/room/back");
 new("/open/snow/npc/fbandit")->move("/open/snow/room/back");
 new("/open/snow/npc/fbandit")->move("/open/snow/room/back");
 new("/open/snow/npc/fbandit")->move("/open/snow/room/room20");
 new("/open/snow/npc/fbandit")->move("/open/snow/room/room20");
 new("/open/snow/npc/fbandit")->move("/open/snow/room/room20");
 new("/open/snow/npc/fbandit")->move("/open/snow/room/room20");
message("mud",HIC"\n劉全書嘆道：唉！唉！看來這場"HIR"血戰"HIC"免不了，只好加入此戰，鞏固雪蒼了。\n"NOR,users());
  call_out("msg4",3,ob);
  return 1;
 }
int msg4(object ob)
{
message("mud",HIR"\n莫無愁目露兇光：可惡！不知是誰把他放出，既然如此！\n"NOR,users());
message("mud",HIR"\n魔刀門徒，大肆殺掠吧，把雪蒼打入萬丈深淵！殺個片甲不留！\n"NOR,users());
return 1;
}

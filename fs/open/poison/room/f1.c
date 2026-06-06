// Room: /u/r/ranko/room/f1.c
inherit ROOM;

void create ()
{
  set ("short", "農田");
  set ("long", @LONG
一大片綠油油的田地橫亙在你面前，豐滿的稻穗幾乎將稻子壓
的貼近地面。不遠處正有許多農民正忙著收割，看來今年似乎是個
豐年。許多頑童正在收割過的田地上跑來跑去，玩的不亦樂乎，附
近不時飛過幾隻白鷺鷥，傳來幾聲嘶鳴聲。
    往東走可回到小路上。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"f2.c",
  "north" : __DIR__"f8.c",
  "east" : __DIR__"pa2.c",
]));
  set("outdoors", "/open/poison");

  setup();
}

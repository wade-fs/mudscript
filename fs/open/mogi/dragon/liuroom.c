//by poloer
// Room: /u/p/poloer/dragon/liuroom.c
inherit ROOM;

void create ()
{
  set ("short", "旅社二樓");
  set ("long", @LONG
一間普通的客房，房內只有一張床和幾張椅子而已。在房內的腳落
放著一塊破舊的牌匾，依稀能看出上面的字，好像是個鏢字。椅子上正
坐著一位打扮僕素的姑娘。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" : "/open/mogi/village/room/room-50",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/mogi/dragon/npc/liugirl" : 1,
  ]));

   set("no_auc",1);
set("no_transmit",1);
set("evil",1);

  setup();
}

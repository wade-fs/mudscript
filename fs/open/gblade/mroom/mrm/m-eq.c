inherit ROOM;
void create()
{
  set ("short", "獎品兌換處");
  set ("long", @LONG

這裡就是專門兌換獎品的地方，只要你得到的忍邪
弟子頭顱到達一定的程度，那你可以試著兌換你想
要的獎品喔！

 『東邊的牆上，還貼著一張羊皮紙(paper)。』

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/m-eq-man": 1,
]));

  set("exits", ([ /* sizeof() == 1 */
"west":__DIR__"r4",
]));
  set("no_fight",1);
  set("no_magic",1);
  set("no_kill",1);
  set("no_smash",1);
  set("no_dest",1);
  set("item_desc", ([ /* sizeof() == 1 */
  "paper" : @LONG
若想知道身上有多少顆雪蒼弟子頭顱，你可以用"ask man about head"。
若想兌換獎品可以用"want xxxxx"。
若想知道能兌換那些獎品請打"list"。
LONG,
]));
  setup();
}

// made by funkcat, copy and re-edit by ccat
inherit BANK;
void create ()
{
  set ("short", "京城乾記錢莊");
  set ("long", @LONG
大門閃閃發光，原來這錢莊的大門竟是用黃金鑄的。不禁佩服乾通
天乾老爺的富可敵國。這裡是乾通天的產業之一，是乾通天所有事業的
資金來源。由於全國錢莊有協定在，因此您的存款可以在各錢莊之間互
相流通。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"h09.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您現有的存款    convert: 換錢幣
    withdraw: 提款               deposit: 存款    
 ",
]));
  set("light_up", 1);

  setup();
}

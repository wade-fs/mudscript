// made by funkcat, copy and re-edit by ccat
inherit BANK;
void create ()
{
  set ("short", "帳房");
  set ("long", @LONG

這裡是魔刀門內提存錢款的錢莊，也同計算門內的收入,這
裡一向以安全，便捷聞名.一張告示(board)告訴你這裡的服
務項目.

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您現有的存款    convert: 換錢幣
    withdraw: 提款               deposit: 存款    
 ",
]));
  set("exits", ([ /* sizeof() == 1 */
"north":__DIR__"r7.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
     "/u/m/moner/npc/officer.c" :1,
]));

  setup();
}

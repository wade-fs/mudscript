
inherit BANK;
void create ()
{
set("short","軍糧發放處");
  set ("long", "
    這是反亂軍們出去打戰所得戰勝品﹐要寄放得地方﹐
也是傭兵們存錢的地方﹐當然在這裡一定會有人在這守衛
不要亂打這裡的主意﹐別人的錢是碰不得的﹐要搶也要搶
對地方﹐你可以看看這兒的公告(board),看看有甚麼服務.
        <<偷竊者被抓罰金xxxxx萬兩黃金>>

");

  set("exits", ([ /* sizeof() == 1 */
"southeast" : __DIR__"r11.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您現有的存款    convert: 換錢幣
    withdraw: 提款               deposit: 存款
         <<偷竊者被抓罰金xxxxx萬兩黃金>>
 ",
]));
  set("light_up", 1);
  setup();
} 

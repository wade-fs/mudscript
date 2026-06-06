// made by funkcat, copy and re-edit by ccat
inherit BANK;
void create ()
{
  set ("short", "平南錢莊");
  set ("long", @LONG
這裡是平南錢莊,雖然地處偏遠,可是你在別處的存款,這裡
還是承認的,你可以看看這兒的公告(board),看看有甚麼服務.
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您現有的存款    convert: 換錢幣
    withdraw: 提款               deposit: 存款    
    cdonate: 把錢轉存至你的幫派之中
 ",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road3",
]));
  set("objects", ([
       "/open/ping/npc/officer-1" :1,
     ]) );
  set("light_up", 1);
  set("donate",1);

  setup();
}

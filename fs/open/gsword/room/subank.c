// made by funkcat, copy and re-edit by ccat
inherit BANK;
void create ()
{
  set ("short", "蜀中錢莊");
	set( "build", 382 );
  set ("long", @LONG
這裡是蜀中最大的錢莊，也是蜀中富豪林萬金的產業，這
裡一向以安全，便捷聞名.  一張告示(board)告訴你這裡的服
務項目.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/gsword/room/su3",
]));

  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您現有的存款    convert: 換錢幣
    withdraw: 提款               deposit: 存款    
    cdonate: 把錢轉存至你的幫派之中
 ",
]));
    set("objects", ([
        "/open/gsword/mob/officer" : 1,
       ]) );

  set("light_up", 1);
   set("donate",1);

  setup();
}

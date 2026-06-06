// made by funkcat, copy and re-edit by ccat
#include <ansi.h>
inherit BANK;
void create ()
{
	set("short",HIY + "＄史家錢莊＄" + NOR);
	set( "build", 36 );
  set ("long", @LONG

　　這裡是本地最大的錢莊，這邊的存款額在全國是數一數二
的，你可以安心的將錢存在這裡。這家錢莊的老闆是大財主史
懷恩，你可以看看這兒的公告(board)，看看有甚麼服務。

LONG);

  set("exits", ([ /* sizeof() == 1 */
	"east" : "/open/port/room/r1-2",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
	服務種類：
		deposit ： 存款    
		withdraw： 提款               
		balance ： 查詢存款
		convert ： 換錢幣

	貨幣種類：
		diamond ： 鑽石
		cash    ： 銀票
		gold    ： 黃金
		silver  ： 銀兩
		coin    ： 銅錢

	注意! 在做極大筆金額的交易時，因為老闆的算術不太好，
	有可能會算錯，巫師可不幫史家錢莊賠錢喔!
	所以建議你還是別冒險，寧願分多次一點，讓他慢慢算。

",
]));
  set("light_up", 1);
  set("donate",1);
  set("objects", ([ /* sizeof() == 1 */
]));

  setup();
}

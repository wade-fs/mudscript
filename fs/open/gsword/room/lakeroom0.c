#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "湖心小築");
  set ("long", @LONG
穿過斑斕的石橋,你走向湖心,這裡是湖心小築,有著杉木製的
樑與柱(post),雖不華麗卻顯的典雅,你倚在橫椅上,腳下是清
涼的湖水,游魚細石(stone),盡在目前,遠方是岸上的遊人與垂
柳,更遠處是蜀州的青山.
LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "stone" : "你正在欣賞湖底的奇石時,卻發現一顆奇異的石子,
上面寫著:
           五行相生,金水木火土.
           五行相剋,金木土水火.

",
  "post" : "杉柱上題著:
             淡泊以明志  寧靜以至遠
",
]));

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/lake0.c",
]));

  set("light_up", 1);

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}

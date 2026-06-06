// Room: /u/f/futzao/room/r1
inherit ROOM;
#include <ansi.h>
 
mapping *weapons;
 
string look_shelf();
void add_weapon();
 
void create ()
{
  set ("short", "兵器庫");
  set ("long", @LONG
這裡是魔教的兵器庫，房間四周的架子(shelf)上放滿了各式各樣的兵器。
架子上放的武器有血龍鞭，青龍鞭，水蛇長鞭，長鞭，小魔鞭， 以上的
兵器有些是稀世兵器，有些是實用，或許你可以找一樣武器來試試看。
你看到牆上貼了一張佈告(note)。
 
LONG);
 
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"room13.c",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "note" : "要申請武器請向守衛報告所需武器種類( report 武器 )。
",
  "shelf" : (: look_shelf :),
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/guard_w.c" : 1,
]));
  set("light_up", 1);
  set("no_clean_up", 1);
 
  setup();
  add_weapon();
}
 
void init()
{
        add_action("do_report", "report");
        add_action("do_take", "take");
        add_action("do_put", "put");
}
 
int do_put(string arg)
{
  object weapon, me = this_player();
  mapping nnew;
   if(!arg) return 0;
  if (sscanf (arg, "%s onto shelf", arg) != 1)
     return 0;
  if(!objectp(weapon = present(arg,me)) || !mapp(weapon->query("weapon_prop")))
	{
		tell_object(me,"你身上並沒有這種武器。\n");
		return 1;
	}
  if( sizeof(weapons) > 20)
     return notify_fail("架子已經都放滿武器了。\n");
  nnew = allocate_mapping(3);
  nnew["name"] = weapon->query("name");
  nnew["id"] = weapon->query("id");
  nnew["file_name"] = base_name(weapon);
  if( !pointerp(weapons) || !sizeof(weapons) )
        weapons = ({ nnew});
  else
        weapons += ({ nnew });
  message_vision(HIC + "$N把"+weapon->name()+"放到架子上。\n" + NOR, me );
  destruct(weapon);
  return 1;
}
 
string look_shelf()
{
        object who = this_player();
        int i;
        if(!sizeof(weapons))
                tell_object(who,"這個架子上空空如也，沒有任何武器。\n");
        else  {
                   write("架子上放有﹕\n\n");
                for(i=0 ; i< sizeof(weapons) ; i++ )
                   printf("%20s(%s)\n",weapons[i]["name"],weapons[i]["id"]);
              }
        return " ";
}
 
int do_report(string weapon)
{
        object who = this_player();
        string id;
        int i, index, j=0;
 
        if( !present("guard", this_object()))
              return notify_fail("根本就沒人你還報告啥啊？直接拿(take)啦！\n");
 
        if( who->query("family/family_name")!="冥蠱魔教" )
              return notify_fail("守衛說道：你不是魔教徒的人，少來煩我。\n");
 
        if(!weapon)
              return notify_fail("守衛說道：你到底要申請哪一種武器? \n");
 
        if(sscanf(weapon, "%s %d", id, index) != 2) {
              id = weapon;
              index = 1;
             }
 
        for(i=0; i<sizeof(weapons); i++) {
              if(weapons[i]["id"] == id) j++;
              if(j == index) break;
             }
 
        if(!j)
              return notify_fail("守衛很不屑地說﹕小子，自己看看架上，有你要的武器嗎?\n");
        else {
              message_vision("守衛拿起"+weapons[i]["name"]+"交給$N。\n", who);
              new(weapons[i]["file_name"])->move(who);
              weapons = weapons[0..i-1] + weapons[i+1..sizeof(weapons)-1];
             }
        return 1;
}
 
int do_take(string weapon)
{
        object who = this_player();
        string id;
        int i, index, j=0;
 
        if( present("guard",this_object()) )
                return notify_fail("守衛對你怒喝道：你要幹什麼！看不懂牆上的佈告啊？\n");
 
        if(!weapon)
              return notify_fail("你到底要拿些什麼東西? \n");
 
        if(sscanf(weapon, "%s %d", id, index) != 2) {
              id = weapon;
              index = 1;
             }
 
        for(i=0; i<sizeof(weapons); i++) {
              if(weapons[i]["id"] == id) j++;
              if(j == index) break;
             }
 
        if(!j)
              return notify_fail("你看清楚一點，有這種東西嗎?\n");
        else {
              message_vision("$N從架上拿起"+weapons[i]["name"]+"。\n", who);
              new(weapons[i]["file_name"])->move(who);
              weapons = weapons[0..i-1] + weapons[i+1..sizeof(weapons)-1];
             }
        return 1;
}
void add_weapon()
{
   mapping nnew;
   int i,j;
   nnew = allocate_mapping(3);
   nnew["id"] = "whip";
   nnew["name"] = "小魔鞭";
   nnew["file_name"] = "/open/poison/obj/mo-whip.c";
 
   if( !pointerp(weapons) || !sizeof(weapons) ) {
       weapons = ({ nnew });
       return ;
      }
 
   for(i=0; i<sizeof(weapons); i++)
      if(weapons[i]["name"] == nnew["name"]) {
               j = 1;
               break;
             }
   if(!j) weapons += ({ nnew });
   return ;
}
void reset()
{
 :: reset();
 add_weapon();
 set("no_clean_up",1);
}

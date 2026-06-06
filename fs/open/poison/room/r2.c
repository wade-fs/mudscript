#include "/open/open.h"
#include <ansi.h>
inherit ROOM;
inherit F_MORE;
string look_shelf();
void add_book();
mapping *books;
void create ()
{
  set ("short", "書房");
  set ("long", @LONG
    這裡是書房，房間四周的書架(shelf)上放滿了各式各樣的書。
架子上的書，有些是記載魔教的歷史，有些是魔教武學的書，有些是
閒情逸致，調野性情的書。假若您是冥蠱教徒，您可以申請書籍。架
上則放了一本供魔教徒查閱用毒及製毒的古老書籍，牆上則貼了一張
申請辦法(note)。
LONG);
 
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"room12.c",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "note" : "架上有使毒之書(use_poison book)及製毒之書(make_poison book)\n"
           "請在此研讀(read)。\n"
           "欲取架上書籍者，請向小童報備(report 書名)。\n",
   "shelf" : (: look_shelf :),
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/boy_b" : 1,
]));
  set("light_up", 1);
 
  setup();
  add_book();
}
 
void init()
{
        add_action("do_report", "report");
        add_action("do_take", "take");
        add_action("do_read", "read");
        add_action("do_put", "put");
}
int do_read(string book)
{
  object me = this_player();
  if(me->query("class") != "poisoner")
        return notify_fail("此地禁止非魔教徒在此研讀。\n");
  if(book == "make_poison book") {
        me->start_more(read_file("/open/poison/obj/make_p_book"));
        return 1;
       }
  else if(book == "use_poison book") {
        me->start_more(read_file("/open/poison/obj/use_p_book"));
        return 1;
       }
  return 0;
}
int do_put(string arg)
{
  object book, me = this_player();
  mapping nnew;
   if(!arg) return 0;
  if (sscanf (arg, "%s onto shelf", arg) != 1)
     return 0;
   if( !objectp(book = present(arg,me)) || !mapp( book->query("skill") ))
	{
	 	tell_object(me,"你身上並沒有這種可讀之書。\n");
		return 1;
	}
  if( sizeof(books) > 20)
     return notify_fail("架子已經都放滿書籍了。\n");
  nnew = allocate_mapping(3);
  nnew["name"] = book->query("name");
  nnew["id"] = book->query("id");
  nnew["file_name"] = base_name(book);
  if( !pointerp(books) || !sizeof(books) )
        books = ({ nnew});
  else
        books += ({ nnew });
  message_vision(HIC + "$N把"+book->name()+"放到架子上。\n" + NOR, me );
  destruct(book);
  return 1;
}
string look_shelf()
{
        object who = this_player();
        int i;
        if(!sizeof(books))
                return "這個架子上空空如也，沒有任何書籍。\n" ;
        else  {
                   write("架子上放有﹕\n\n");
                for(i=0 ; i< sizeof(books) ; i++ )
                   printf("%20s(%s)\n",books[i]["name"],books[i]["id"]);
                   return "";
              }
}
 
int do_report(string book)
{
        object who = this_player();
        string id;
        int i, index, j=0;
 
        if( !present("boy", this_object()))
              return notify_fail("根本就沒人你還報告啥啊？直接拿(take)啦！\n");
 
        if( who->query("family/family_name")!="冥蠱魔教" )
                return notify_fail("小書童說道：你不是魔教徒的人，少來煩我。\n");
 
        if(!books)
                return notify_fail("小書童說道：你要申請哪一種書？\n");
 
        if(sscanf(book, "%s %d", id, index) != 2) {
              id = book;
              index = 1;
             }
 
        for(i=0; i<sizeof(books); i++) {
              if(books[i]["id"] == id) j++;
              if(j == index) break;
             }
 
        if(!j)
              return notify_fail("小書童說道﹕報歉，書架上並沒有你要的書。\n");
        else {
              message_vision("小書童拿起一本"+books[i]["name"]+"交給$N。\n", who);
              new(books[i]["file_name"])->move(who);
              books = books[0..i-1] + books[i+1..sizeof(books)-1];
             }
        return 1;
}
 
int do_take(string book)
{
        object who = this_player();
        string id;
        int i, index, j=0;
 
        if( present("boy",this_object()) )
                return notify_fail("小書童對你怒喝道：你要幹什麼！看不懂牆上的佈告啊？\n");
 
        if(!book)
              return notify_fail("你到底要拿些什麼東西? \n");
 
        if(sscanf(book, "%s %d", id, index) != 2) {
              id = book;
              index = 1;
             }
 
        for(i=0; i<sizeof(books); i++) {
              if(books[i]["id"] == id) j++;
              if(j == index) break;
             }
 
        if(!j)
              return notify_fail("你看清楚一點，有這種東西嗎?\n");
        else {
              message_vision("$N從架上拿起"+books[i]["name"]+"。\n", who);
              new(books[i]["file_name"])->move(who);
              books = books[0..i-1] + books[i+1..sizeof(books)-1];
             }
        return 1;
}
void add_book()
{
   mapping nnew;
   int i,j;
  nnew =allocate_mapping(3);
   nnew["id"] = "poison book";
   nnew["name"] = "基本毒經";
   nnew["file_name"] = "/open/poison/obj/pbasebook.c";
 
   if( !pointerp(books) || !sizeof(books) ) {
       books = ({ nnew });
       return ;
      }
 
   for(i=0; i<sizeof(books); i++)
      if(books[i]["name"] == nnew["name"]) {
               j = 1;
               break;
             }
   if(!j) books += ({ nnew });
   return ;
}
 
void reset()
{
 :: reset();
 add_book();
}

inherit "/obj/book";

#define BOOK_PATH "/open/gsword/obj/"
#define BOOK_NAME "map1"
#define C_BOOK_NAME "仙劍派內部配置圖"

void create()
{
  ::create();
  set_name( C_BOOK_NAME, ({ "map" }) );
  set("long", "仙劍派內部配置圖,你可以讀讀它(read map).\n"
  );
  set("value",  3);
  set ( "book_path", BOOK_PATH + BOOK_NAME );
  setup();
}

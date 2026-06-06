//修正路徑錯誤 by blazakira 2010/12/25

inherit "/obj/book";
//#define BOOK_PATH "/u/w/wing/gold_blade/obj/"
#define BOOK_PATH "/open/gblade/obj/"
#define BOOK_NAME "paper"
#define C_BOOK_NAME "字條"

void create()
{
  ::create();
  set_name( C_BOOK_NAME, ({ "paper" }) );
  set("long", "一張由王家大小姐依照古文書的內容，翻譯而寫下的紙條。\n"
  );
  set("unit","張");
  set("value", 0 );
  set ( "book_path", BOOK_PATH + BOOK_NAME );
  setup();
}

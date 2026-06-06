//book.c

inherit ITEM;

void create()
{
  set_name("暗器入門",({"book"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "本");
    set("long",
      "一本普通的武學入門書籍。\n");
    set("value",300);
    set("material", "paper");
    set("skill", ([
      "name"      : "throwing",
                              // to learn this skill.
      "sen_cost"  : 30,       // gin cost every time study this
      "difficulty": 20,       // the base int to learn this skill
                              // modify is gin_cost's (difficulty - int)*5%
      "max_skill" : 10,
                              // from this object.
    ]) );
  }
  setup();
}

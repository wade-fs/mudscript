//book.c

inherit ITEM;

void create()
{
set_name("神秘書籍",({"secret_book","book"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"話說秦始皇,為了保有王位,特地派徐福至東瀛求取長生不老藥。
 這本書可能是徐福從東瀛所求取回來的,有類似長生不老的神奇\功\效\.
 你可以\閱\讀\看\看\(read secret_book).\n");
                set("value",0);
                set("material", "paper");
        }
        setup();
}

void init()
{
add_action("do_read","read");
}

int do_read(string str)
{
  object me=this_player();
  if(str!="secret_book") {
  tell_object(me,"你想讀什麼?\n");
  return 1;
                       }
    else if(me->query("functions/young/level") >= 1){
      tell_object(me,"你已經學過了。\n");
        return 1;

                       }
  else if (!me->query("secret_book",1)){
  tell_object(me,"你並沒有殺死天子,無\法\閱\讀\此\書\籍.\n");
  return 1;


}
  else {
 tell_object(me,"你照著書上的口訣練了一遍，身體感到輕鬆無比,臉上的\皺\紋\少\了\許\多。\n書上最後寫著：返\老\返\童\術\用\法：perform literate.young\n");
  me->delete("secret_book");
  me->set("functions/young/level",1);
  return 0;
       }
}


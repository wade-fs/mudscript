// Room: /obj/guardh
//#define SOL1 "/open/capital/npc/Wsoldier"
//#define SOL2 "/open/capital/npc/Wsoldier"
//#define SOL3 "/open/capital/npc/Wsoldier"
//#define SOL4 "/open/capital/npc/Wsoldier"

inherit ROOM;
//string *order = ({"SOL1","SOL2","SOL3","SOL4"});
//object soldier;
  
void create ()
{
  set ("short", "小廣場");
  set ("long", @LONG
地板上鋪滿了石磚，似乎是集合用的。前方有棟兩層的屋子，屋子
旁立了兩隻石獅子，門上還有個牌匾寫著禁衛軍部，京城的禁衛軍就是
由這地方統一指揮的。旁邊有個馬房，是用來和大內聯絡用的，皇帝的
命令第一時間傳到這裡再由禁軍總指揮下達命令，絲毫延誤不得。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/capital/room/r47",
]));

  set("light_up", 1);
//  set("gopath", "east");

//  call_out("new_soldier",1);
  
  setup();

}
/*
void new_soldier()
{  
  soldier=new(order[random(4)]);
  if(soldier->is_fighting()==0)
  {   
    tell_room(environment(soldier),"禁衛軍好像接到命令的樣子, 忽然匆匆忙忙的跑回禁衛軍部了\n");
    destruct(soldier);
  }
  soldier->move(this_object());
  tell_room(this_object(),"禁衛軍部的大門呀的一聲打開, 一位禁衛軍匆匆的裡面走出來\n");
  call_out("around",30+random(30));
}

int around()
{
        string dir;
        dir = environment(soldier)->query("gopath");
        if(soldier->is_fighting()==0)
        {
          command("go "+dir);
          soldier->add("times");
        }
        call_out("around",random(30)+30);
        if( soldier->query("time") >= 150 )
        destruct(soldier);
}
*/

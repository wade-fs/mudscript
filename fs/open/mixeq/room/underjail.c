inherit ROOM;
#include <ansi.h>
#include <underjail.txt>

void do_act();
void old_create()
{
    string long;

    this_object()->set("short","地牢");
    this_object()->set("no_auc", 1);
    this_object()->set("no_transmit", 1);
    this_object()->set("light_up",-1);
    this_object()->set("msg_num",-1);
    long=print_underjail_msg();
    set("long",long);

    setup();
}
void old_reset()
{
    
    this_object()->set("have_called_mob",0);

    return ;
}
void init()
{
    if(!this_object()->query("have_called_mob")){
      call_out("create_mob",1);
    }
}
int valid_leave(object me, string dir)
{
    int i;
    object *all;

    if(wizardp(me) && me->query("env/nomob")==1) return ::valid_leave(me,dir);
    if(this_object()->query("have_called_mob")){
      all=all_inventory(this_object());
      for(i=0;i<sizeof(all);i++){
        if(all[i]->query("id")=="vampire" && living(all[i]) && !all[i]->query_temp("unconcious"))
           return notify_fail("你忽然聽到身旁出現了一陣令人毛骨悚然的聲音：你以為你可以這麼輕易的離開嗎？\n");
      }
    }
    else
    {
      write("四周實在是太暗了，你必需要花點時間適應才可以看得到出口\n");
      return 0;
    }
    return ::valid_leave(me,dir);
}

int create_mob()
{
    int i,j,flag,mob_kind;
    object mob,*all,ppl;
    string mob_file;

    all=all_inventory(this_object());
    flag=0;
    for(i=0;i<sizeof(all);i++){
      if(userp(all[i])){
        ppl=all[i];
        flag=1;;
      }
      if(flag) break;
    }
    if(!flag) return 1;
    this_object()->set("have_called_mob",1);
    do_act();  
    if(wizardp(this_player()) && this_player()->query("env/nomob")==1) return 1;
    if(20 > random(100)) return 1;  //反向思考，就是80%的機會怪物會出現
    j=2+random(2);
    if(!mob_kind=this_object()->query("mob_kind")) mob_kind=0;
    switch(mob_kind){
      case 0:
         mob_file=__DIR__"npc/vampire.c";
        break;
      case 1:
         mob_file=__DIR__"npc/vampire1.c";
        break;
      default:
         mob_file=__DIR__"npc/vampire.c";
    }
    mob=new(mob_file);
    tell_room(this_object(),sprintf(HIR + "忽然幾聲大叫，幾隻%s向你撲了過來!!\n" + NOR,mob->name()));
    destruct(mob);
    for(i=0;i<j;i++)
    {
      mob=new(mob_file);
      mob->move(this_object());
    }
    return 1;
}
    
void do_act()
{
    mapping new_out;
    mixed *exits;
    int i;

    new_out=this_object()->query("new_exits");
    if(!new_out || !mapp(new_out)) return ;
    exits=keys(new_out);
    for(i=0;i<sizeof(exits);i++){
      this_object()->set("exits/"+exits[i],new_out[exits[i]]);
    }
    return ;
}


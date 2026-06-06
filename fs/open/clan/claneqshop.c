//shop.c by chun 1995.10.19
//Modify By AceLan 99.8.1  改寫成幫派 eq 室的模式...

#include <ansi.h>
#include <room.h>

inherit ROOM;
inherit CHINESE_D;
inherit F_FINANCE;
inherit F_MORE;

mapping sells = ([ ]);		//      sells[id] = short();
mapping item_type = ([ ]);    	//      item_type[id] = skill_type or armor_type
mapping c_name = ([ ]);	//      c_name[id] = player()->query("name");
mapping names = ([ ]); 	//      names[id] = file_name(id);
mapping player = ([ ]);          //      player[id] = player()->query("id");
mapping tradename = ([ ]);  //      tradename[id] = id;
mapping unit = ([ ]);		//      unit[id] = ob->query("unit")
mapping num = ([ ]);		//      number

void do_more(object me, string cmd , int line );
int put_ob(object ob);
int put_all();

void create()
{
  set("no_clean_up",1);
}

void init()
{
  add_action("do_put","put");
  add_action("do_get","take");
  add_action("do_list","list");
}

void get_thing(string arg)
{
  if( num[ arg] == 1)
  {
    map_delete( tradename , arg );
    map_delete( item_type , arg );
    map_delete( sells , arg );
    map_delete( names , arg );
    map_delete( c_name , arg );
    map_delete( player , arg );
    map_delete( unit , arg );
    map_delete( num, arg );
  }
  else
    num[ arg]= num[ arg]- 1;
}


int do_put(string arg)
{
  object ob, me=this_player();
  int index=1;

  if( !arg )
    return notify_fail("你要將什麼東西交給美麗的櫃臺小姐ㄚ？\n");

  if (arg == "all") return put_all();

  // 這樣可以賣第二項物品, good 範例
  if (sscanf (arg, "%s %d", arg, index) == 2)
    if (index < 1) index = 1;

  if( !(ob = present(arg+" "+index, me)) )
    return notify_fail("什麼...你要將自己交給美麗的櫃臺小姐？\n");

  if (!put_ob( ob))
    write ("這件東西太珍貴了，美麗的櫃臺小姐不能收。\n");
  else
    write ("美麗的櫃臺小姐將你交給他的東西分門別類的收好了。\n");
  return 1;
}

int put_all()
{
  object *inv;
  int    i;

  inv = all_inventory(this_player());
  for (i=0; i<sizeof(inv); i++)
    put_ob( inv[i]);

  write ("美麗的櫃臺小姐將你交給他的東西分門別類的收好了。\n");
  return 1;
}

int put_ob(object ob)
{
  object me=this_player();
  string arg;
  int valu;

  arg = base_name( ob);
  valu= ob->query("value");

  if( ob->query("no_drop") || ob->query_temp("secured") || ob->query("no_sell") )
    return 0;
  if( ob->query_autoload())
    return 0;
  if (ob->query("money_id"))
    return 0;

  if(!valu){
write ("你給櫃臺的"+ob->query("name")+"是一件無價之寶，美麗的櫃臺小姐就將它偷偷的收了起來。\n");
  destruct(ob);
  return 1;
  }
  if(!intp(valu)){
  write ("你給櫃臺的"+ob->query("name")+"是一件無價之寶，美麗的櫃臺小姐就將它偷偷的收了起來。\n");
    destruct(ob);
    return 1;
    }

  if (!valu || valu <= 0) {
    write ("你給櫃臺的"+ob->query("name")+"是一件無價之寶，美麗的櫃臺小姐就將它偷偷的收了起來。\n");
    destruct(ob);
    return 1;
  }

  message_vision(HIY"$N將"+ob->query("name")+"送給了美麗的櫃臺小姐。\n"NOR, me);

// 改成重複物品不會被吃掉...AceLan...98.8.18...
// 此處為物品重複部份...
  if( names[arg] == base_name(ob) && sells[arg] == ob->short())
  {
    num[ arg]=num[ arg]+ 1;
  }
// 此部份為原物品不重複部份...
  else
  {
    player[arg] = me->query("id");
    names[arg] = base_name(ob);
    c_name[arg] = me->query("name");
    sells[arg] = ob->short();
    tradename[arg] = ob->query("id");
    unit[arg] = ob->query("unit");
    num[arg] = 1;

    if( ob->query("armor_type"))
       item_type[arg]= "armor";
    else if( !( item_type[arg]= ob->query("skill_type")))
       item_type[arg]= "item";
  }

  destruct(ob);
  return 1;
}

int do_list(string arg)
{
  string *k;

  printf("美麗的櫃臺小姐對你說:我們這邊有最新的武器及防具，請慢慢挑選...\n");

  if( sizeof(k= keys(sells)) != 0 )
     do_more(this_player(), arg, 0);
  else  // 空的...來點東西吧...hoho...
  {
     switch( random( 6))
     {
         case 0:
            printf("%-40s感謝 櫃臺小姐(Beauty) 獨家贊助提供\n", "華歌爾小衣");
            break;
         case 1:
            printf("%-40s感謝 櫃臺小姐(Beauty) 獨家贊助提供\n", "戴安芬小褲");
            break;
         case 2:
            printf("%-40s感謝 櫃臺小姐的媽媽(Mama) 獨家贊助提供\n", "潘婷少女系列");
            break;
         case 3:
            printf("%-40s感謝 櫃臺小姐(Beauty) 獨家贊助提供\n", "好佳在衛生棉");
            break;
         case 4:
            printf("%-40s感謝 櫃臺小姐(Beauty) 獨家贊助提供\n", "小黃瓜");
            break;
         case 5:
            printf("%-40s感謝 小豬頭(Small Pig) 獨家贊助提供\n", "檸檬");
            break;
     }
  }
  return 1;
}

int do_get(string arg)
{
  object ob, me=this_player();
  string *k= keys( sells);
  int flag= 0;

  if( !arg )
    return notify_fail("你要跟美麗的櫃臺小姐領取什麼東西ㄚ？\n");
// 這邊問題挺大的...
  for( int i= 0; i< sizeof( k); i++)
  {
    if( arg == tradename[k[i]] )
    {
      flag= 1;
      arg= k[i];
      break;
    }
  }
  if( !flag)
    return notify_fail("美麗的櫃臺小姐說：這款裝備是目前最搶手的，已經被人領完囉...\n");

  ob = new(names[arg]);
  ob->move(me);
  get_thing(arg);
  message_vision("$N跟美麗的櫃臺小姐要了一"+ob->query("unit")+ob->short()+"\n", me);

  return 1;
}

void do_more(object me, string cmd , int line )
{
   int i, j;
   string *k, list="";
   k = keys(sells);

   if( !cmd)
   {
      for(i = line; line<sizeof(k); line++)
      {
         j= num[ k[ line]];
         list += sprintf("%s%-35s感謝 %s(%s) 獨家贊助提供\n", 
            j == 1 ? "" : chinese_number(j)+ unit[k[line]], 
            sells[ k[ line]], c_name[ k[ line]], player[ k[ line]]);
      }
   }
   else
   {
      for(i = line; line<sizeof(k); line++)
      {
         j= num[ k[ line]];
         if( item_type[ k[ line]] == cmd )
            list += sprintf("%s%-35s感謝 %s(%s) 獨家贊助提供\n", 
            j == 1 ? "" : chinese_number(j)+ unit[k[line]], 
            sells[ k[ line]], c_name[ k[ line]], player[ k[ line]]);
      }
   }
   me->start_more(list);
}

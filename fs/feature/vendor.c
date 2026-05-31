// vendor.c
// 改成自動回應字串
// 改成自動找零錢
// 增加中英文模式並行, rewrite by wade 1/4/1996
// 相同東西可以一次買完, hmm....商店似乎也可以一次賣...

#include <room.h>
inherit NPC;

// 這是給 buy 命令用的, 只是傳回物品價值, 後面還有另一步
int sell_object(object me, string what)
{
  object	ob;
  string	*goods;
  int		g, n, s, i, j;

  // 找出物品的值
  goods = query("vendor_goods");

  if (sscanf (what, "%d %s", n, what) != 2) n = 1;
  if (n > 40) return notify_fail("相同的物品最多一次只能買40個!!!\n");

  // 當然, 沒賣該物就不必繼續交易了
  if (!pointerp(goods) || sizeof(goods) == 0) return
	notify_fail ("對方根本沒東西可賣, 你想幹嘛?\n"); 

  for (g=0; g<sizeof(goods); g++)
    if (goods[g]->id(what))
      break;

  if (g == sizeof(goods)) return notify_fail ("抱歉, 沒這東西\n");

  s = goods[g]->query("value") * n;

  if ( s > 0 && me->can_afford(s) ) {
    me->pay_money(s);

    j = me->query_int()-10;
    for (i=s=0; i<n; i++)
	s += 10+random(j);
    me->improve_skill("trade",s);
    if ( me->query_skill("trade") > 50 )
	me->set_skill("trade",100);

    if( goods[g]->query_amount() > 0 )
    {
    	ob = new(goods[g]);
    	ob->set_amount(n);
    	ob->move(me);
    }
    else
      for (i=0; i<n; i++) {
      	ob = new(goods[g]);
    	ob->move(me);
      }
    message_vision ("$N向$n買下"+chinese_number(n)+ob->query("unit") + ob->name() + "。\n",
      me, this_object() );
    
    return 1;
  }
  else
    return notify_fail("你的錢不夠。\n");
}

string price_string(int v)
{
  if( v%10000 == 0 )
    return (v/10000) + "兩黃金";
  if( v%100 == 0 )
    return (v/100) + "兩銀子";
  return v + "文錢";
}

// 這是給 list 命令用的
int do_vendor_list(string arg)
{
  string *goods;
  int i;

  // 沒賣東西?
  if( !pointerp(goods = query("vendor_goods")) ) return 0;
  write ("您可以購買下列這些東西:\n");
  for(i=0; i<sizeof(goods); i++)
    printf("%-65s﹕%s\n",
      goods[i]->short(),
      price_string(goods[i]->query("value")) );
  return 1;  
}

void init()
{
  ::init();
  this_object()->set("class","officer");
  this_object()->set("officer_type","food");
// for /daemon/class/officer/cmds/command
  add_action ("do_vendor_list", "list");
}

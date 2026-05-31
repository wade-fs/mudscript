// buy.c

inherit F_CLEAN_UP;

int help(object);

int main(object me, string arg)
{
  string item, targ;
  object ob, owner,*living;
  int price, afford, n,i;

  seteuid(getuid());
  if( !arg ) return help(me);
  if( sscanf(arg, "%s from %s", item, targ)!=2 )
  {
   item = arg;
   living=all_inventory(environment(me));
    for(i=0;i<sizeof(living);i++){
      if(living[i]->query("vendor_goods")){
        owner=living[i];
        break;
      }
    }
  if(!owner) return help(me);
  }
  else
  {
    targ = lower_case(targ);

    if( !objectp(owner = present(targ, environment(me))) ||
      userp(owner) || !living(owner))
    return notify_fail("只能跟非玩家的'人'買東西!!\n");
  }
  return owner->sell_object(me, item);
}

int help(object me)
{
   write( @HELP
指令格式: buy [數量] <東西> from <生物>
指令說明 :
          這一指令讓你可以從某些生物身上買到物品。
          當你要大量地買相同的東西的時候，記得給數量。
範    例 :
        buy torch from girl
        buy 100 bandage from vendor
警    告 :
	  大量買相同物件請不要用 <數量> buy <東西> from <生物>
	  因為這樣會讓您容易變成機器人, 上述的命令數視為 <數量> 個.
	  此外, 上述的方式也非常耗 CPU, 是前面說明的 <數量> 倍,
	  綜合以上說明, 在此特別呼籲各位用本命令特別提供的語法買東西.
HELP
   );
   return 1;
}

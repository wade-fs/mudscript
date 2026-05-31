int check_gift(object me)
{
  if(sizeof(me->query_temp("armor")))
    return write("請先把防具脫掉。\n");
  if(me->query_condition("giftout"))
    return write("請等筋骨異常運行完成，否則會造成精神錯亂。\n");
  if(me->query("legging_add_gift") ||
      me->query("armband_add_gift") ||
      me->query("belt_add_gift") ||
      me->query("cloak_add_gift") ||
      me->query("pants_add_gift") ||
      me->query("plate_add_gift"))
    return write("現在吃還太急了，請稍後。\n");
  return 1;
}

static void
<%=c_iterator%>(na_loop_t *const lp)
{
    size_t   i;
    char    *p1;
    ssize_t  s1;
    size_t  *idx1;
    VALUE    x = lp->option;
    dtype    y;
    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1, idx1);
    y = m_num_to_data(x);
    if (idx1) {
        for (; i--;) {*(dtype*)(p1+*(idx1++)) = y;}
    } else {
        for (; i--;) {*(dtype*)(p1) = y; p1+=s1;}
    }
}

/*
  Fill elements with other.
  @overload <%=op_map%> other
  @param [Numeric] other
  @return [NArray::<%=class_name%>] self.
*/
static VALUE
<%=c_instance_method%>(VALUE self, VALUE val)
{
    ndfunc_arg_in_t ain[2] = {{cT,0},{sym_option}};
    ndfunc_t ndf = { <%=c_iterator%>, FULL_LOOP, 2, 0, ain, 0 };

    na_ndloop(&ndf, 2, self, val);
    return self;
}

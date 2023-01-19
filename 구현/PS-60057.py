s = "sisisisisisisi"
s_len = len(s)
result = []
for i in range(1, s_len//2+1):
  result.append(s_len)
  pointer = i
  find_ch = s[0:i]
  while pointer < s_len:
    if s.find(find_ch, pointer) == pointer:
      print("l")
      pointer += i
        # Consider Count num
      result[i-1] -= i-1
      while pointer < s_len:
        if s.find(find_ch, pointer) == pointer:
          pointer += i
          result[i-1] -= i
        else:
          find_ch = s[pointer:pointer+i]
          pointer += i
          break
    else:
      find_ch = s[pointer:pointer+i]
      pointer += i
rr = min(result)

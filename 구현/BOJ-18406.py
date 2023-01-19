	#1551 ~ #1555
  """
  18406번 : 럭키스트레이트
  https://www.acmicpc.net/problem/18406
  """
n = input()
pivot = int(len(n) / 2) #6 -> 3 번까지
left = 0
right = 0
for i in range (pivot):
	 left += int(n[i])
	 right += int(n[i+pivot])
result = ""
if left == right:
	 result = "LUCKY"
else:
	 result = "READY"
print (result)

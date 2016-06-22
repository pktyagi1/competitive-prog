class RectangularGrid:

	def countRectangles(self, width, height):
		minval=min(width,height)
		maxval=max(width,height)
		hor=minval+1
		ver=maxval+1
		tot=((hor*(hor-1))/2)*((ver*(ver-1))/2)
		sq=0
		for i in range(1,minval+1):
			sq+=((minval-i+1)*(maxval-i+1))
		#print str(tot)+" "+str(sq)
		return tot-sq

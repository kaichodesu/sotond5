SamacSys ECAD Model
12783902/1061851/2.49/2/2/Resistor

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "s115"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.15) (shapeHeight 1.15))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "ERA6VK" (originalName "ERA6VK")
		(multiLayer
			(pad (padNum 1) (padStyleRef s115) (pt -1.175, 0) (rotation 90))
			(pad (padNum 2) (padStyleRef s115) (pt 1.175, 0) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1 0.625) (pt 1 0.625) (width 0.2))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1 0.625) (pt 1 -0.625) (width 0.2))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1 -0.625) (pt -1 -0.625) (width 0.2))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1 -0.625) (pt -1 0.625) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -2.025, 0) (radius 0.05) (startAngle 0.0) (sweepAngle 0.0) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -2.025, 0) (radius 0.05) (startAngle 180.0) (sweepAngle 180.0) (width 0.2))
		)
		(layerContents (layerNumRef 30)
			(line (pt -3.125 1.825) (pt 2.75 1.825) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 2.75 1.825) (pt 2.75 -1.825) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 2.75 -1.825) (pt -3.125 -1.825) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt -3.125 -1.825) (pt -3.125 1.825) (width 0.05))
		)
	)
	(symbolDef "ERA-6VEB1000V" (originalName "ERA-6VEB1000V")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 0 mils -35 mils) (rotation 0]) (justify "UpperLeft") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 700 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 700 mils -35 mils) (rotation 0]) (justify "UpperRight") (textStyleRef "Default"))
		))
		(line (pt 200 mils 50 mils) (pt 500 mils 50 mils) (width 6 mils))
		(line (pt 500 mils 50 mils) (pt 500 mils -50 mils) (width 6 mils))
		(line (pt 500 mils -50 mils) (pt 200 mils -50 mils) (width 6 mils))
		(line (pt 200 mils -50 mils) (pt 200 mils 50 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 550 mils 250 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "ERA-6VEB1000V" (originalName "ERA-6VEB1000V") (compHeader (numPins 2) (numParts 1) (refDesPrefix R)
		)
		(compPin "1" (pinName "1") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "2") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "ERA-6VEB1000V"))
		(attachedPattern (patternNum 1) (patternName "ERA6VK")
			(numPads 2)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
			)
		)
		(attr "Mouser Part Number" "667-ERA-6VEB1000V")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Panasonic/ERA-6VEB1000V?qs=rI7uf1IzohT7rLgO%252BB7NcQ%3D%3D")
		(attr "Manufacturer_Name" "Panasonic")
		(attr "Manufacturer_Part_Number" "ERA-6VEB1000V")
		(attr "Description" "Thin Film Chip Resistor, High Stability & Reliability, 0805, 0.25W")
		(attr "Datasheet Link" "http://industrial.panasonic.com/cdbs/www-data/pdf/RDM0000/RDM0000C331.pdf")
		(attr "Height" "0.65 mm")
	)

)

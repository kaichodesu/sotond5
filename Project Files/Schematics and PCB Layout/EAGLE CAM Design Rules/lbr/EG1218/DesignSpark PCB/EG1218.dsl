SamacSys ECAD Model
12863335/1061851/2.49/3/4/Switch

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "c150_h100"
		(holeDiam 1)
		(padShape (layerNumRef 1) (padShapeType Ellipse)  (shapeWidth 1.500) (shapeHeight 1.500))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 1.500) (shapeHeight 1.500))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "EG1218" (originalName "EG1218")
		(multiLayer
			(pad (padNum 1) (padStyleRef c150_h100) (pt 0.000, 0.000) (rotation 90))
			(pad (padNum 2) (padStyleRef c150_h100) (pt 2.500, 0.000) (rotation 90))
			(pad (padNum 3) (padStyleRef c150_h100) (pt 5.000, 0.000) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 1.900, 0.000) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 28)
			(line (pt -3.3 2) (pt 8.3 2) (width 0.2))
		)
		(layerContents (layerNumRef 28)
			(line (pt 8.3 2) (pt 8.3 -2) (width 0.2))
		)
		(layerContents (layerNumRef 28)
			(line (pt 8.3 -2) (pt -3.3 -2) (width 0.2))
		)
		(layerContents (layerNumRef 28)
			(line (pt -3.3 -2) (pt -3.3 2) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -3.3 2) (pt 8.3 2) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 8.3 2) (pt 8.3 -2) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt 8.3 -2) (pt -3.3 -2) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -3.3 -2) (pt -3.3 2) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt -5.5 3) (pt 9.3 3) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt 9.3 3) (pt 9.3 -3) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt 9.3 -3) (pt -5.5 -3) (width 0.1))
		)
		(layerContents (layerNumRef 30)
			(line (pt -5.5 -3) (pt -5.5 3) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -4.5 0) (pt -4.5 0) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -4.4, 0) (radius 0.1) (startAngle 180.0) (sweepAngle 180.0) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -4.3 0) (pt -4.3 0) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(arc (pt -4.4, 0) (radius 0.1) (startAngle .0) (sweepAngle 180.0) (width 0.2))
		)
	)
	(symbolDef "EG1218" (originalName "EG1218")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 3) (pt 0 mils -200 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -225 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(line (pt 200 mils 100 mils) (pt 700 mils 100 mils) (width 6 mils))
		(line (pt 700 mils 100 mils) (pt 700 mils -300 mils) (width 6 mils))
		(line (pt 700 mils -300 mils) (pt 200 mils -300 mils) (width 6 mils))
		(line (pt 200 mils -300 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 750 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "EG1218" (originalName "EG1218") (compHeader (numPins 3) (numParts 1) (refDesPrefix S)
		)
		(compPin "1" (pinName "NC") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "COMM") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "NO") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "EG1218"))
		(attachedPattern (patternNum 1) (patternName "EG1218")
			(numPads 3)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
			)
		)
		(attr "Mouser Part Number" "612-EG1218")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/E-Switch/EG1218?qs=xDsBkp9LkocT0c8K%252B5e%2FgA%3D%3D")
		(attr "Manufacturer_Name" "E-Switch")
		(attr "Manufacturer_Part_Number" "EG1218")
		(attr "Description" "Slide Switches PC MNT 3 PIN SLIDE")
		(attr "Datasheet Link" "https://sten-eswitch-13110800-production.s3.amazonaws.com/system/asset/product_line/data_sheet/119/EG.pdf")
		(attr "Height" "7.4 mm")
	)

)

# Import data
aws dynamodb batch-write-item --request-items file://mystore.json

#### SCANS ####

# Perform scan of ProductOrders table:
aws dynamodb scan --table-name mystore

#### QUERIES ####

# Use Key-Conditions Parameter: (linux/mac)
aws dynamodb query  --table-name mystore --key-conditions '{ "clientid":{ "ComparisonOperator":"EQ", "AttributeValueList": [ {"S": "chris@example.com"} ] } }'

# Use Key-Conditions Parameter: (Windows)
aws dynamodb query  --table-name mystore --key-conditions "{ \"clientid\":{ \"ComparisonOperator\":\"EQ\", \"AttributeValueList\": [ {\"S\": \"chris@example.com\"} ] } }"


# Use Key-Condition-Expression Parameter: (linux/mac)
aws dynamodb query --table-name mystore --key-condition-expression "clientid = :name" --expression-attribute-values '{":name":{"S":"chris@example.com"}}'

# Use Key-Condition-Expression Parameter: (Windows)
aws dynamodb query --table-name mystore --key-condition-expression "clientid = :name" --expression-attribute-values "{\":name\":{\"S\":\"chris@example.com\"}}"